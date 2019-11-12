import subprocess
import simplejson as json

def clear(data):
	data["Instruction"] = "  "
	data["Mnemonic"] = "  "
	data["FirstOperand"] = "  "
	data["SecondOperand"] = "  "
	data["ThirdOperand"] = " "


data = {}
cnt = 0
# batcmd=' sudo ./nanoBench.sh -asm "ADD RAX, RBX" -config configs/cfg_Skylake_common.txt -median -n_measurements 10000'
# result = subprocess.check_output(batcmd, shell=True)
#print result
#print "================================================="
f=open("instructions.txt" ,"r")
jf = open("instructions.json" ,"w")
content = f.read()
lines = content.split('\n')
for i in range(len(lines)):
	write = True
	if  i%3==2:
		if len(lines[i].split(' '))>1 :
			data["Instruction"] = lines[i]
		else :
			data["Instruction"] = lines[i]
		cnt+=1

	elif   i%3==0:
		if len(lines[i].split(' '))>1 :
			data["Mnemonic"] = lines[i].split(' ')[1]
		else :
			data["Mnemonic"] = lines[i]
		cnt+=1

	elif   i%3==1:
		operands =lines[i].split(',')
		data["FirstOperand"] = operands[0]
		if len(operands)>1 :

			data["SecondOperand"] = operands[1]
			if len(operands)>2 :

				data["ThirdOperand"] = operands[2]
			else :
				data["ThirdOperand"] = " "
		else :
			data["SecondOperand"] = " "
			data["ThirdOperand"] = " "
		cnt+=1

	if cnt == 3  :

		jf.write(json.dumps(data, indent=4, sort_keys=True)+"\n")
		cnt = 0
		clear(data)

