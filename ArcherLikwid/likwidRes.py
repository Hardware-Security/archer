import subprocess
import json

List = []
for cmd in ['UOPS_RETIRE', 'TLB_INSTR', 'MEM', 'FLOPS_AVX']:

	batcmd=' likwid-perfctr -c 0 -g "'+cmd+'" likwid-bench -t copy -w S0:1GB:1'
	text = subprocess.check_output(batcmd, stderr=subprocess.STDOUT, shell=True)

	data = {}

	section = 0
	cols = []

	lines = text.split('\n')
	for l in lines:

	    if l and l[0] == '+':
		section = (section + 1) % 3
		continue
	    if section == 0 and ':' in l:
		key, value = l.split(':')
		data[key] = value.strip()
		continue
	    if section == 1:
		cols = l.split('|')[1:-1]
		cols = [col.strip() for col in cols]
		data[cols[0]] = {}
		continue
	    if section == 2:
		row = l.split('|')[1:-1]
		row = [r.strip() for r in row]
		data[cols[0]][row[0]] = {}
		for i in range(1, len(cols)):
		    col = cols[i]
		    data[cols[0]][row[0]][col] = row[i]
		continue

	json_data = json.dumps(data)
	parsed = json.loads(json_data)

	event_data = {}
	for key in data['Event']:
	    if data['Event'][key]['Core 0'] != '-':
		event_data[key] = int(data['Event'][key]['Core 0'])
	json_data = json.dumps(event_data)
	parsed = json.loads(json_data)
	List.append(event_data)
	print()
	print(json.dumps(parsed, indent=4, sort_keys=True))

#print(List)
merged_dict = {}
for l in List:
	merged_dict = {key: value for (key, value) in (l.items() + merged_dict.items())}
#print(merged_dict)
json_mergerd = json.dumps(merged_dict)
pars = json.loads(json_mergerd)
print()
print(json.dumps(pars, indent=4, sort_keys=True))





