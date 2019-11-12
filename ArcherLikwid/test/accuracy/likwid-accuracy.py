#!/usr/bin/env python

import os, sys, os.path
import re
import subprocess
import socket
import stat
import getopt

# Needed for Wiki page output
import glob
import statistics

bench_plain = "./likwid-bench-plain"
bench_marker = "/home/hpc/unrz/unrz139/Apps-arm/bin/likwid-bench"
bench_papi = "./likwid-bench-papi"
perfctr = "/home/hpc/unrz/unrz139/Apps-arm/bin/likwid-perfctr"
topology = "/home/hpc/unrz/unrz139/Apps-arm/bin/likwid-topology"
topology_name = re.compile("^CPU name:\s+(.*)")
topology_stepping = re.compile("^CPU stepping:\s+(\d*)")
topology_type = re.compile("^CPU type:\s+(.*)")
topology_sockets = re.compile("^Sockets:\s+(\d+)")
topology_corespersocket = re.compile("^Cores per socket:\s+(\d+)")
topology_threadspercore = re.compile("^Threads per core:\s+(\d+)")
testlist = "SET.txt"
testfolder = "TESTS"
resultfolder = "RESULTS"
hostname = socket.gethostname()
picture_base = ".."
topology_outputfile = "topology.dat"
nrThreads = 1

gnu_colors = ["red","blue","green","black"]#,"brown", "gray","violet", "cyan", "magenta","orange","#4B0082","#800000","turquoise","#006400","yellow"]
gnu_marks = [5,13,9,2]#,3,4,6,7,8,9,10,11,12,14,15]

units = { "L2" : "MByte/s", "L3" : "MByte/s", "MEM" : "MByte/s", "HA" : "MByte/s",
          "FLOPS_SP" : "MFLOP/s", "FLOPS_DP" : "MFLOP/s", "FLOPS_AVX" : "MFLOP/s",
          "DATA": "Load/Store ratio", "BRANCH" : "Instructions per branch",
          "CLOCK" : "Instructions", "UOPS" : "UOPs"}
translate_group = {"CLOCK" : "INST_RETIRED_ANY", "UOPS" : "UOPS_RETIRED_ANY"}

wiki = False
papi = False
only_wiki = False
sets = []
out_pgf = False
out_gnuplot = False
out_grace = False
scriptfilename = "create_plots.sh"
out_script = False
test_set = {}
plain_set = {}
corrected_set = {}
marker_set = {}
papi_set = {}

if not os.path.exists(bench_marker):
    print "Please run make before using likwid-accuracy.py"
    sys.exit(1)
if not os.path.exists(perfctr):
    print "Cannot find likwid-perfctr"
    sys.exit(1)


def usage():
    print "Execute and evaluate accuracy tests for LIKWID with likwid-bench and likwid-perfctr"
    print
    print "-h/--help:\tPrint this help text"
    print "-s/--sets:\tSpecifiy testgroups (comma separated). Can also be set in SET.txt"
#    print "--wiki:\t\tBesides testing write out results in Google code wiki syntax"
#    print "--only_wiki:\tDo not run benchmarks, read results from file and write out results in Google code wiki syntax"
    print "-c <nrThreads>:\tSet number of threads. The accuracy tool uses the E notation of likwid like E:N:<nrThreads>:1:2. Default is 1 thread."
    print "Picture options:"
    print "--pgf:\t\tCreate TeX document for each test with PGFPlot"
    print "--gnuplot:\tCreate GNUPlot script for each test"
    print "--grace:\tCreate Grace script that can be evaluated with gracebat"
    print "--script:\tActivate recording of commands in a bash script"
    print "--scriptname:\tRecord commands to create pictures in file (default: %s)" % (os.path.join(destfolder,scriptfilename))


def get_groups():
    groups = {}
    p = subprocess.Popen(perfctr+" -a", shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    p.wait()
    if p.returncode != 0:
        return groups
    for line in p.stdout.read().split("\n"):
        if line.startswith("-") or not line.strip(): continue
        if line.startswith("Available"): continue
        linelist = re.split("\s+", line.strip())
        name = linelist[0]
        description = " ".join(linelist[1:])
        groups[name] = description
    return groups

def get_test_groups(groupdict):
    groups = {}
    if len(sets) > 0:
        setlist = sets
    else:
        setfp = open("SET.txt",'r')
        setlist = setfp.read().strip().split("\n")
        setfp.close()

    filelist = glob.glob(testfolder+"/*.txt")
    for name in setlist:
        if name in get_groups():
            tests = []
            file = os.path.join(testfolder, name) + ".txt"
            if not os.path.exists(file): continue
            fp = open(file,'r')
            finput = fp.read().strip().split("\n")
            fp.close()
            for line in finput:
                if line.startswith("TEST"):
                    tests.append(line.split(" ")[1])
            groups[name] = tests


    return groups

def get_avail_tests():
    tests = []
    p = subprocess.Popen(bench_marker+" -a", shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    p.wait()
    if p.returncode != 0:
        return tests
    for line in p.stdout.read().split("\n"):
        m = re.match("(.*) - (.*)", line)
        if m:
            name, desc = m.groups()
            tests.append(name)
    return tests

def write_topology(path):
    try:
        f = open(os.path.join(path, topology_outputfile),"w")
    except:
        print "Cannot write topology file %s" % (os.path.join(path, topology_outputfile),)
        return
    p = subprocess.Popen(topology, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    p.wait()
    if p.returncode != 0:
        return
    f.write(p.stdout.read())
    f.close()

def approx(in1, in2):
    if in1 > (0.95*in2) or in1 < (1.05*in2):
        return 1
    return 0

def legend(file1, file2):
    input1 = []
    input2 = []
    numbers1 = []
    numbers2 = []
    try:
        f=open(file1,"r")
        input1 = f.read().strip().split("\n")
        f.close()
    except:
        print "Cannot open file "+file1
    try:
        f=open(file2,"r")
        input2 = f.read().strip().split("\n")
        f.close()
    except:
        print "Cannot open file "+file2
    if len(input1) == 0 and len(input2) == 0:
        return "no"
    for line in input1:
        numbers1.append(line.split(" ")[1])
    for line in input2:
        numbers2.append(line.split(" ")[1])
    if float(numbers1[1]) > float(numbers1[-1]) and float(numbers2[1]) > float(numbers2[-1]):
        return "no"
    elif float(numbers1[1]) < float(numbers1[-1]) and float(numbers2[1]) < float(numbers2[-1]):
        return "so"
    elif approx(float(numbers1[1]), float(numbers1[-1])) and approx(float(numbers2[1]), float(numbers2[-1])):
        return "so"
    return "no"


def write_pgf(group, test, plain_file, marker_file, scale=0.0,papi_file=None, execute=False, script=None):
    printgrp = group
    if translate_group.has_key(group):
        printgrp = translate_group[group]
    filename = os.path.join(destfolder,printgrp+"_"+test+".tex")
    sizelist = []
    sizeindex = []
    lentry = "north east"
    if legend(plain_file, marker_file) == "so":
        lentry = "south east"
    for i,variant in enumerate(test_set[group][test]["variants"]):
        sizelist.append(variant)
        sizeindex.append(str((i+0.5)*test_set[group][test]["RUNS"]))
    fp = open(filename,'w')
    fp.write("\documentclass{article}\n")
    fp.write("\usepackage{pgfplots}\n")
    fp.write("\\begin{document}\n")
    fp.write("% cut from here\n")
    fp.write("\\begin{tikzpicture}\n")
    fp.write("\\begin{axis}[xmin=0,xmax=%d,xlabel={Size - %d runs each}, ylabel={%s},title={Group %s - Test %s},legend pos=%s,xtick=data,width=.75\\textwidth,xticklabels={%s},xtick={%s}]\n" % (test_set[group][test]["RUNS"]*len(test_set[group][test]["variants"]),test_set[group][test]["RUNS"],units[group],printgrp.replace("_","\_"),test.replace("_","\_"),lentry,",".join(sizelist),",".join(sizeindex)))
    fp.write("\\addplot+[red,mark=square*,mark options={draw=red, fill=red}] table {%s};\n" % (os.path.basename(plain_file),))
    fp.write("\\addlegendentry{bench};\n")
    if scale > 0.0:
        fp.write("\\addplot+[blue,mark=*,mark options={draw=blue, fill=blue}] table[x index=0, y expr=\\thisrowno{1}*%f] {%s};\n" % (scale, os.path.basename(plain_file),))
        fp.write("\\addlegendentry{scaled bench};\n")
    fp.write("\\addplot+[green,mark=diamond*,mark options={draw=green, fill=green}] table {%s};\n" % (os.path.basename(marker_file),))
    fp.write("\\addlegendentry{perfctr};\n")
    if papi and papi_file:
        fp.write("\\addplot+[black,mark=triangle*,mark options={draw=black, fill=black}] table {%s};\n" % (os.path.basename(papi_file),))
        fp.write("\\addlegendentry{papi};\n")
    fp.write("\\end{axis}\n")
    fp.write("\\end{tikzpicture}\n")
    fp.write("% stop cutting here\n")
    fp.write("\\end{document}\n")
    fp.close()
    if execute:
        cmd = "cd %s && pdflatex %s && cd -" % (os.path.dirname(filename), os.path.basename(filename),)
        p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        p.wait()
        if p.returncode != 0:
            print p.stdout.read()
        p.stdout.close()
    if script:
        script.write("pdflatex %s\n" % (os.path.basename(filename),))
    return filename

def write_gnuplot(group, test, plain_file, marker_file, scale = 1.0, papi_file=None, execute=False, script=None):
    printgrp = group
    if translate_group.has_key(group):
        printgrp = translate_group[group]
    filename = os.path.join(destfolder,printgrp+"_"+test+".plot")
    fp = open(filename,'w')
    for i,color in enumerate(gnu_colors):
        fp.write("set style line %d linetype 1 linecolor rgb '%s' lw 2 pt %s\n" % (i+1, color,gnu_marks[i]))
    fp.write("set terminal jpeg enhanced\n")
    fp.write("set encoding utf8\n")
    fp.write("set title 'Group %s - Test %s'\n" % (printgrp.replace("_", "\_"), test.replace("_", "\_"),))
    if legend(plain_file, marker_file) == "no":
        fp.write("set key top right\n")
    else:
        fp.write("set key bottom right\n")
    fp.write("set output '%s'\n" % (os.path.basename(os.path.join(destfolder,printgrp+"_"+test+".jpg")),))
    fp.write("set xlabel 'Size - %d runs each'\n" % (test_set[group][test]["RUNS"],))
    fp.write("set ylabel '%s'\n" % (units[group],))
    fp.write("set yrange  [0:]\n")
    #fp.write("set xtics 0,%d,%d\n" % (test_set[group][test]["RUNS"], test_set[group][test]["RUNS"]*len(test_set[group][test]["variants"]),))
    fp.write("set xtics %d\n" % (test_set[group][test]["RUNS"]*len(test_set[group][test]["variants"]),))
    for i,variant in enumerate(test_set[group][test]["variants"]):
        fp.write("set xtics add (\"%s\" %f)\n" % (variant, (i*test_set[group][test]["RUNS"])+(0.5*test_set[group][test]["RUNS"]),))
    plot_string = "plot '%s' using 1:3 title 'Reference' with linespoints ls 1, \\\n"  % (os.path.basename(plain_file),)
    if scale > 0.0:
        plot_string = plot_string+" '%s' using 1:($3*%f) title 'Scaled Reference' with linespoints ls 2, \\\n" % (os.path.basename(plain_file), scale,)
    plot_string = plot_string+" '%s' using 1:3 title 'Measurement (LIKWID)' with linespoints ls 3" % (os.path.basename(marker_file),)
    if papi and papi_file:
        plot_string += ", \\\n '%s' using 1:3 title 'Measurement (PAPI)' with linespoints ls 4\n" % (os.path.basename(papi_file),)
    fp.write(plot_string+"\n")
    fp.close()
    if execute:
        cmd = "cd %s && gnuplot %s && cd -" % (os.path.dirname(filename), os.path.basename(filename),)
        print cmd
        p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        p.wait()
        if p.returncode != 0:
            print p.stdout.read()
        p.stdout.close()
    if script:
        script.write("gnuplot %s\n" % (os.path.basename(filename),))
    return filename

def write_grace(group, test, plain_file, correct_file, marker_file, papi_file=None, execute=False, script=None):
    printgrp = group
    if translate_group.has_key(group):
        printgrp = translate_group[group]
    filename = os.path.join(destfolder,printgrp+"_"+test+".bat")
    agrname = os.path.join(destfolder,printgrp+"_"+test+".agr")
    pngname = os.path.join(destfolder,printgrp+"_"+test+".png")
    if execute or script:
        plain_file = os.path.basename(plain_file)
        marker_file = os.path.basename(marker_file)
        correct_file = os.path.basename(correct_file)
        if papi_file: papi_file = os.path.basename(papi_file)
        pngname = os.path.basename(pngname)
        agrname = os.path.basename(agrname)
    cmd_options = "-autoscale xy -nxy %s -nxy %s -nxy %s " % (plain_file, correct_file, marker_file,)
    if papi and papi_file:
        cmd_options += "-nxy %s " % (papi_file,)
    out_options = "-hdevice PNG -printfile %s " % (pngname,)
    out_options += "-saveall %s" % (agrname,)
    fp = open(filename,'w')
    fp.write("title \"Group %s - Test %s\"\n" % (printgrp, test,))
    fp.write("xaxis label \"Run\"\n")
    fp.write("xaxis label char size 1.2\n")
    fp.write("xaxis ticklabel char size 1.2\n" % (units[group],))
    fp.write("yaxis label \"%s\"\n")
    fp.write("yaxis label char size 1.2\n")
    fp.write("yaxis ticklabel char size 1.2\n")
    if legend(plain_file, marker_file) == "no":
        fp.write("legend 0.8,0.7\n")
    else:
        fp.write("legend 0.2,0.7\n")
    fp.write("s0 legend \"bench\"\n")
    fp.write("s0 symbol 2\n")
    fp.write("s0 symbol size 1\n")
    fp.write("s0 symbol color 2\n")
    fp.write("s0 symbol pattern 1\n")
    fp.write("s0 symbol fill color 2\n")
    fp.write("s0 symbol fill pattern 1\n")
    fp.write("s0 symbol linewidth 2\n")
    fp.write("s0 symbol linestyle 1\n")
    fp.write("s0 line type 1\n")
    fp.write("s0 line color 2\n")
    fp.write("s0 line linestyle 1\n")
    fp.write("s0 line linewidth 2\n")
    fp.write("s0 line pattern 1\n")
    fp.write("s1 legend \"scaled bench\"\n")
    fp.write("s1 symbol 3\n")
    fp.write("s1 symbol size 1\n")
    fp.write("s1 symbol color 4\n")
    fp.write("s1 symbol pattern 1\n")
    fp.write("s1 symbol fill color 4\n")
    fp.write("s1 symbol fill pattern 1\n")
    fp.write("s1 symbol linewidth 2\n")
    fp.write("s1 symbol linestyle 1\n")
    fp.write("s1 line type 1\n")
    fp.write("s1 line color 4\n")
    fp.write("s1 line linestyle 1\n")
    fp.write("s1 line linewidth 2\n")
    fp.write("s1 line pattern 1\n")
    fp.write("s2 legend \"perfctr\"\n")
    fp.write("s2 symbol 4\n")
    fp.write("s2 symbol size 1\n")
    fp.write("s2 symbol color 3\n")
    fp.write("s2 symbol pattern 1\n")
    fp.write("s2 symbol fill color 3\n")
    fp.write("s2 symbol fill pattern 1\n")
    fp.write("s2 symbol linewidth 2\n")
    fp.write("s2 symbol linestyle 1\n")
    fp.write("s2 line type 1\n")
    fp.write("s2 line color 3\n")
    fp.write("s2 line linestyle 1\n")
    fp.write("s2 line linewidth 2\n")
    fp.write("s2 line pattern 1\n")
    if papi and papi_file:
        fp.write("s3 legend \"papi\"\n")
        fp.write("s3 symbol 5\n")
        fp.write("s3 symbol size 1\n")
        fp.write("s3 symbol color \"black\"\n")
        fp.write("s3 symbol pattern 1\n")
        fp.write("s3 symbol fill color \"black\"\n")
        fp.write("s3 symbol fill pattern 1\n")
        fp.write("s3 symbol linewidth 2\n")
        fp.write("s3 symbol linestyle 1\n")
        fp.write("s3 line type 1\n")
        fp.write("s3 line color \"black\"\n")
        fp.write("s3 line linestyle 1\n")
        fp.write("s3 line linewidth 2\n")
        fp.write("s3 line pattern 1\n")
    fp.close()
    if execute:
        cmd = "cd %s && gracebat %s -param %s %s && cd -" % (os.path.dirname(filename), cmd_options, os.path.basename(filename),out_options,)
        p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        p.wait()
        if p.returncode != 0:
            print p.stdout.read()
        p.stdout.close()
    if script:
        script.write("gracebat %s -param %s %s\n" % (cmd_options, os.path.basename(filename),out_options,))
    return filename

def get_bytes(s):
    m = re.match("(\d+)[bB]", s)
    if m:
        return int(m.group(1))
    m = re.match("(\d+)[kK][bB]", s)
    if m:
        return int(m.group(1))*1024
    m = re.match("(\d+)[mM][bB]", s)
    if m:
        return int(m.group(1))*1024*1024
    m = re.match("(\d+)[gG][bB]", s)
    if m:
        return int(m.group(1))*1024*1024*1024

def get_sizestr(b):
    bint = int(b)
    if int(bint / 1024.0) == 0:
        return "%dB" % (bint)
    if int(bint / (1024.0*1024.0)) == 0:
        if bint % (1024) == 0:
            return "%dkB" % (bint/(1024))
        else:
            return "%dB" % (bint)
    if int(bint / (1024.0*1024.0*1024.0)) == 0:
        if bint % (1024*1024) == 0:
            return "%dMB" % (bint/(1024*1024))
        else:
            return "%dkB" % (bint/(1024))
    if int(bint / (1024.0*1024.0*1024.0*1024.0)) == 0:
        if bint % (1024*1024*1024) == 0:
            return "%dGB" % (bint/(1024*1024*1024))
        else:
            return "%dMB" % (bint/(1024*1024))

def get_variants(start, end, step):
    bstart = get_bytes(start)
    bend = get_bytes(end)
    bstep = get_bytes(step)
    return [ get_sizestr(x) for x in range(bstart, bend, bstep) ] + [end]

try:
    opts, args = getopt.getopt(sys.argv[1:], "hs:c:", ["help", "sets=","script","scriptname=","wiki","only_wiki=","pgf","gnuplot","grace","papi"])
except getopt.GetoptError as err:
    print str(err)
    usage()
    sys.exit(2)

if len(opts) == 0:
    usage()
    sys.exit(1)

for o, a in opts:
    if o in ("-h","--help"):
        usage()
        sys.exit(0)
    if o == "--wiki":
        wiki = True
    if o == "--only_wiki":
        only_wiki = True
        hostname = a
    if o == "--papi":
        papi = True
    if o == "-c":
        try:
            nrThreads = int(a)
        except:
            print "Argument to -c not valid. Must be a number"
            sys.exit(1)
    if o == "--pgf":
        out_pgf = True
    if o == "--gnuplot":
        out_gnuplot = True
    if o == "--grace":
        out_grace = True
    if o in ("-s","--sets"):
        sets = a.split(",")
    if o == "--script":
        out_script = True
    if o == "--scriptname":
        scriptfilename = a

if len(sets) == 0 and not os.path.exists(testlist):
    print "Cannot find file %s containing list of testgroups" % (testlist,)
    sys.exit(1)
if not os.path.exists(testfolder):
    print "Cannot find folder %s containing the testgroups" % (testfolder,)
    sys.exit(1)


if len(sets) == 0:
    fp = open(testlist,'r')
    tmp = fp.read().split("\n")
    for item in tmp:
        if not item.strip() or item.startswith("#"): continue
        sets.append(item)
    fp.close()
for line in sets:
    if not line.strip() or line.startswith("#"): continue
    filename = "%s/%s.txt" % (testfolder,line.strip(),)
    if os.path.exists(filename):
        groupname = line.strip()
        testfp = open(filename,'r')
        for line in testfp.read().split("\n"):
            if line.startswith("GROUP"):
                match = re.match("^GROUP\s+(\.+)", line)
                if match:
                    groupname = match.group(1)
                    break
        testfp.close()
        test_set[groupname] = {}
        plain_set[groupname] = {}
        corrected_set[groupname] = {}
        marker_set[groupname] = {}
        papi_set[groupname] = {}
        testfp = open(filename,'r')
        test = None
        for i,testline in enumerate(testfp.read().split("\n")):
            if test and not testline.strip(): test = None
            if testline.startswith("REGEX_BENCH"):
                test_set[groupname]["REGEX_BENCH"] = re.compile(" ".join(testline.split(" ")[1:]))
            if testline.startswith("REGEX_PERF"):
                test_set[groupname]["REGEX_PERF"] = re.compile(" ".join(testline.split(" ")[1:]))
            if testline.startswith("REGEX_PAPI"):
                test_set[groupname]["REGEX_PAPI"] = re.compile(" ".join(testline.split(" ")[1:]))
            if testline.startswith("TEST"):
                test = testline.split(" ")[1]
                test_set[groupname][test] = {}
                test_set[groupname][test]["WA_FACTOR"] = 0.0
                plain_set[groupname][test] = {}
                corrected_set[groupname][test] = {}
                marker_set[groupname][test] = {}
                papi_set[groupname][test] = {}
            if testline.startswith("RUNS") and test:
                test_set[groupname][test]["RUNS"] = int(testline.split(" ")[1])
            if testline.startswith("WA_FACTOR") and test:
                test_set[groupname][test]["WA_FACTOR"] = float(testline.split(" ")[1])
            if testline.startswith("VARIANT") and test:
                linelist = re.split("\s+",testline);
                variant = linelist[1]
                if not test_set[groupname][test].has_key("variants"):
                    test_set[groupname][test]["variants"] = []
                test_set[groupname][test][variant] = linelist[2]
                test_set[groupname][test]["variants"].append(linelist[1])
                plain_set[groupname][test][variant] = []
                corrected_set[groupname][test][variant] = []
                marker_set[groupname][test][variant] = []
                papi_set[groupname][test][variant] = []
            if testline.startswith("RANGE") and test:
                linelist = re.split("\s+",testline);
                start = linelist[1]
                end = linelist[2]
                step = linelist[3]
                if not test_set[groupname][test].has_key("variants"):
                    test_set[groupname][test]["variants"] = []
                variants = get_variants(start, end, step)
                for variant in variants:
                    test_set[groupname][test][variant] = "1"
                    test_set[groupname][test]["variants"].append(variant)
                    plain_set[groupname][test][variant] = []
                    corrected_set[groupname][test][variant] = []
                    marker_set[groupname][test][variant] = []
                    papi_set[groupname][test][variant] = []
        testfp.close()


if len(test_set.keys()) == 0:
    print "Cannot find any group in %s" % (testlist)
    sys.exit(1)

if not os.path.exists(resultfolder):
    os.mkdir(resultfolder)

destfolder = os.path.join(resultfolder, hostname)
if not os.path.exists(destfolder):
    os.mkdir(destfolder)

write_topology(destfolder)

avail_tests = get_avail_tests()

if not only_wiki:

    scriptfile = os.path.join(destfolder, scriptfilename)
    script = open(scriptfile,'w')
    script.write("#!/bin/bash\n")


    for group in test_set.keys():
        perfctr_string = "%s -f -C E:N:%d:1:2 -g %s -m " % (perfctr, nrThreads, group,)
        no_scale = False
        for test in test_set[group].keys():
            if test.startswith("REGEX"): continue
            if test not in avail_tests:
                print "Skip Group %s Test %s" % (group, test,)
                continue
            filebase = "%s_%s" % (group, test)

            file_plain = os.path.join(destfolder,filebase+"_plain.dat")
            #raw_plain = os.path.join(destfolder,filebase+"_plain.raw")
            file_correct = os.path.join(destfolder,filebase+"_correct.dat")
            file_marker = os.path.join(destfolder,filebase+"_marker.dat")
            raw_marker = os.path.join(destfolder,filebase+"_marker.raw")
            fp_ref = open(file_plain,'w')
            fp_ref.write("#Counter Size Reference Scaled_Reference\n")
            fp_scale_ref = open(file_correct,'w')
            fp_scale_ref.write("#Counter Size Scaled_Reference\n")
            fp_likwid = open(file_marker,'w')
            fp_likwid.write("#Counter Size Measurement\n")
            rawfp_likwid = open(raw_marker,'w')
            if papi:
                file_papi = os.path.join(destfolder, filebase+"_papi.dat")
                raw_papi = os.path.join(destfolder, filebase+"_papi.raw")
                fp_papi = open(file_papi,'w')
                fp_papi.write("#Counter Size Measurement\n")
                rawfp_papi = open(raw_papi,'w')
            else:
                file_papi = None
                raw_papi = None
            counter = 1
            print "Group %s Test %s" % (group, test,)
            for size in test_set[group][test]["variants"]:
                if size.startswith("RUNS"): continue
                print "Size "+size+": ",
                bench_options = "-t %s -w N:%s:%d" % (test, size, nrThreads)
                for i in range(0,test_set[group][test]["RUNS"]):
                    print "*",
                    sys.stdout.flush()
                    # Run with LIKWID instrumented likwid-bench and likwid-perfctr
                    rawfp_likwid.write(perfctr_string+" "+bench_marker+" "+bench_options+"\n")
                    p = subprocess.Popen(perfctr_string+" "+bench_marker+" "+bench_options, shell=True, stdout=subprocess.PIPE,stderr=subprocess.STDOUT,executable="/bin/bash")
                    stdout = ""
                    try:
                        p.wait()
                        stdout = p.stdout.read()
                        p.stdout.close()
                    except:
                        sys.exit(1)
                    found_bench = False
                    found_perfctr = False
                    for line in stdout.split("\n"):
                        if p.returncode == 0:
                            match = test_set[group]["REGEX_PERF"].match(line)
                            if match:
                                marker_set[group][test][size].append(float(match.group(1)))
                                #fp_likwid.write(str(counter)+" "+str(float(match.group(1)))+"\n")
                                fp_likwid.write("%d %d %f\n" % (counter, get_bytes(size), float(match.group(1))))
                                found_perfctr = True
                            match = test_set[group]["REGEX_BENCH"].match(line)
                            if match:
                                found_bench = True
                                value = float(match.group(1)) * test_set[group][test]["WA_FACTOR"]
                                plain_set[group][test][size].append(match.group(1))
                                corrected_set[group][test][size].append(str(value))
                                fp_ref.write("%d %d %f %f\n" % (counter, get_bytes(size), float(match.group(1)), value))
                                #fp_ref.write(str(counter)+" "+match.group(1)+"\n")
                                #fp_scale_ref.write(str(counter)+" "+str(value)+"\n")
                                fp_scale_ref.write("%d %d %f\n" % (counter, get_bytes(size), value))
                        rawfp_likwid.write(line+"\n")
                    if not found_bench:
                        value = "0"
                        plain_set[group][test][size].append(value)
                        corrected_set[group][test][size].append(value)
                        #fp_ref.write(str(counter)+" "+value+"\n")
                        fp_ref.write("%d %d %f %f\n" % (counter, get_bytes(size), float(match.group(1)), float(value)))
                        #fp_scale_ref.write(str(counter)+" "+value+"\n")
                        fp_scale_ref.write("%d %d %f\n" % (counter, get_bytes(size), value))
                        no_scale = True
                    if not found_perfctr:
                        marker_set[group][test][size].append(0)
                        #fp_likwid.write(str(counter)+" "+str(0)+"\n")
                        fp_likwid.write("%d %d %f\n" % (counter, get_bytes(size), 0.0))
                    counter += 1
                print("")
            fp_ref.close()
            fp_scale_ref.close()
            fp_likwid.close()
            rawfp_likwid.close()
            if papi:
                fp_papi.close()
                rawfp_papi.close()
            if no_scale:
                test_set[group][test]["WA_FACTOR"] = 0.0
            if out_pgf:
                pgf_file = write_pgf(group, test, file_plain, file_marker, test_set[group][test]["WA_FACTOR"],file_papi, script=script)
            if out_gnuplot: plot_file = write_gnuplot(group, test, file_plain, file_marker, test_set[group][test]["WA_FACTOR"], file_papi, script=script)
            if out_grace: grace_file = write_grace(group, test, file_plain, file_correct, file_marker, file_papi, script=script)


    script.close()
    os.chmod(scriptfile, stat.S_IRWXU)
