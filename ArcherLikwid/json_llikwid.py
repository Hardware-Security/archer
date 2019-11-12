import subprocess
import simplejson as json

def clear(data):
    cdata = {}
    data = cdata


pcdata = {}
pc = open("data.json" ,"w")

f=open("instructions.json" ,"r")
with open('benchmark.asm', 'r') as benFile:
    # read a list of lines into data
    data = benFile.readlines()


for i, line in enumerate(f):
    if i%7== 2:

        with open('benchmark1.asm', 'w') as benFile:
            benFile.writelines( data[0:15] )

            hex = "db " + "0x"+line.split('"')[3][0:2]
            benFile.write(hex)
            benFile.write("\n")

            hex = "db " + "0x"+line.split('"')[3][2:4]
            benFile.write(hex)
            benFile.write("\n")

            hex = "db " + "0x"+line.split('"')[3][4:6]
            benFile.write(hex)
            benFile.write("\n")

            hex = "db " + "0x"+line.split('"')[3][6:8]
            benFile.write(hex)
            benFile.write("\n")

            hex = "db " + "0x"+line.split('"')[3][8:10]
            benFile.write(hex)
            benFile.write("\n")

            hex = "db " + "0x"+line.split('"')[3][10:12]
            benFile.write(hex)
            benFile.write("\n")

            hex = "db " + "0x"+line.split('"')[3][12:14]
            benFile.write(hex)
            benFile.write("\n")

            hex = "db " + "0x"+line.split('"')[3][14:16]
            benFile.write(hex)
            benFile.write("\n")

            benFile.write("\n")
            benFile.writelines( data[24: len(data)] )
        
        # every thing happen in here
        batcmd='/bin/bash -c "echo LIKWID_LIB=$(dirname $(which likwid-perfctr))/../lib/" && export LIKWID_LIB=/usr/local/bin/../lib/  && /bin/bash -c "echo LIKWID_INCLUDE=$(dirname $(which likwid-perfctr))/../include/" && export LIKWID_INCLUDE=/usr/local/bin/../include/ && nasm -f elf64 benchmark.asm && gcc -c -DLIKWID_PERFMON -I$LIKWID_INCLUDE test.c -o test.o && gcc benchmark.o test.o -o a.out -L$LIKWID_LIB -llikwid'
        result = subprocess.check_output(batcmd, shell=True)
        print result
        batcmd='export LD_LIBRARY_PATH="$LIKWID_LIB:$LD_LIBRARY_PATH"'
        result = subprocess.check_output(batcmd, shell=True)
        print "+++++++++++++++++++++++++++++"
        print result
        batcmd='likwid-perfctr -C S0:0 -g L3 -m ./a.out'
        text = subprocess.check_output(batcmd, shell=True)
        print text
        print "================================================="
        
	pcdata = {}

	section = 0
	cols = []

	lines = text.split('\n')
	for l in lines:

	    if l and l[0] == '+':
		section = (section + 1) % 3
		continue
	    if section == 0 and ':' in l:
		key, value = l.split(':')
		pcdata[key] = value.strip()
		continue
	    if section == 1:
		cols = l.split('|')[1:-1]
		cols = [col.strip() for col in cols]
		pcdata[cols[0]] = {}
		continue
	    if section == 2:
		row = l.split('|')[1:-1]
		row = [r.strip() for r in row]
		pcdata[cols[0]][row[0]] = {}
		for i in range(1, len(cols)):
		    col = cols[i]
		    pcdata[cols[0]][row[0]][col] = row[i]
		continue

	event_data = {}
	for key in pcdata['Event']:
	    if pcdata['Event'][key]['Core 0'] != '-':
		event_data[key] = int(pcdata['Event'][key]['Core 0'])

	metric_data = {}
	for key in pcdata['Metric']:
	    if pcdata['Metric'][key]['Core 0'] != '-':
		metric_data[key] = float(pcdata['Metric'][key]['Core 0'])


	res = {key: value for (key, value) in (event_data.items() + metric_data.items())}
	json_res = json.dumps(res)
	parsed = json.loads(json_res)
	print()
	print(json.dumps(parsed, indent=4, sort_keys=True))



f.close()
pc.close()
benFile.close()

#check_output
