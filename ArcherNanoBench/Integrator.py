import subprocess
import json
import mysql.connector


# Insert Into the database

mydb = mysql.connector.connect(
  host="IpHere",
  user="UserHere",
  passwd="PasswordHere",
  database="DatabaseHere"
)
filepath = 'Path to instructions Json'

mycursor = mydb.cursor()
instructionID = 1

EachElementJson = ""

with open(filepath) as fp:
   line = fp.readline()
   EachElementJson += line
   cnt = 1

   while line:
		line = fp.readline()
		EachElementJson += line
		cnt += 1
		if cnt % 7 == 0 :
			print("=========================================")
			#print(EachElementJson)
			ParsedJson = json.loads(EachElementJson)
			tempInstruction = ParsedJson["Instruction"]
			tempInstruction = tempInstruction.strip()

			twoCharHexs = [tempInstruction[i:i + 2] for i in range(0, len(tempInstruction), 2)]
			finalInstruction = '.ascii \\"'

			for item in twoCharHexs :
				finalInstruction += '\\x' + item

			finalInstruction += '\\"'

			print("________________________" + finalInstruction)
			#instruction = ParsedJson["Mnemonic"]
			#
			#FirstOperand = ParsedJson["FirstOperand"]
			#SecondOperand = ParsedJson["SecondOperand"]
			#ThirdOperand = ParsedJson["ThirdOperand"]
			#
			#if FirstOperand and (not FirstOperand.isspace()):
			#	instruction += "	" + FirstOperand		
			#	
			#if SecondOperand and (not SecondOperand.isspace()):
			#	instruction += "," + SecondOperand			
			#	
			#if ThirdOperand and (not ThirdOperand.isspace()):
			#	instruction += "," + ThirdOperand
				
			#print("["+str(instructionID)+"] " +instruction)
			EachElementJson = ""
			#instruction = 'ADD RAX, RBX'
			#instruction = 'add byte ptr [rsi + 0x5c], al'
			#instruction = '.ascii \\"\\x84\\x82\\x01\\x76\\"'
			#'.ascii \\"\\x00\\x04\\x05\\x11\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\"'

			# Combine it with Intel TSX (It've been done in bash script)

			instruction = finalInstruction
			data = {}
			
			batcmd=' sudo ./nanoBench.sh -asm "'+instruction+'" -config configs/cfg_Skylake_common.txt -median -n_measurements 500'
			result = subprocess.check_output(batcmd, shell=True)
			
			lines = result.split('\n')
			for liner in lines:
				if liner and (not liner.isspace()):
					data[liner.split(':')[0].replace(' ','').strip()] = liner.split(':')[1].replace(' ','').replace("-","").strip()
			
			print "================================================="
			
			
			data["Instruction"] = instruction
			data["InstructionID"] = instructionID
			
			
			json_data = json.dumps(data)
			parsed = json.loads(json_data)
			print(json.dumps(parsed, indent=4, sort_keys=True))
			
			print "================================================="
			
			
			
			sql = """INSERT INTO ResultsDB.NanoBenchResults (
				
			Instruction ,
			InstrID ,
			BR_INST_RETIRED_ALL_BRANCHES ,
			BR_MISP_RETIRED_LL_BRANCHES ,
			Corecycles,
			Instructionsretired,
			MEM_LOAD_RETIRED_L1_HIT ,
			MEM_LOAD_RETIRED_L1_MISS ,
			MEM_LOAD_RETIRED_L2_HIT ,
			MEM_LOAD_RETIRED_L2_MISS , 
			MEM_LOAD_RETIRED_L3_HIT ,
			MEM_LOAD_RETIRED_L3_MISS ,
			RDTSC , 
			Referencecycles ,
			UOPS_DISPATCHED_PORT_PORT_0 ,
			UOPS_DISPATCHED_PORT_PORT_1 , 
			UOPS_DISPATCHED_PORT_PORT_2 ,
			UOPS_DISPATCHED_PORT_PORT_3 ,
			UOPS_DISPATCHED_PORT_PORT_4 , 
			UOPS_DISPATCHED_PORT_PORT_5 ,
			UOPS_DISPATCHED_PORT_PORT_6 ,
			UOPS_DISPATCHED_PORT_PORT_7 ,  
			UOPS_EXECUTED_THREAD ,
			UOPS_ISSUED_ANY
			
			) VALUES (
			
			%s ,/*Instruction*/
			%s ,/*InstrID*/
			%s ,/*BR_INST_RETIRED_ALL_BRANCHES*/
			%s ,/*BR_MISP_RETIRED_LL_BRANCHES*/
			%s ,/*Corecycles VARCHAR(20)*/
			%s ,/*Instructionsretired*/
			%s ,/*MEM_LOAD_RETIRED_L1_HIT*/
			%s ,/*MEM_LOAD_RETIRED_L1_MISS*/
			%s ,/*MEM_LOAD_RETIRED_L2_HIT*/
			%s ,/*MEM_LOAD_RETIRED_L2_MISS*/ 
			%s ,/*MEM_LOAD_RETIRED_L3_HIT*/
			%s ,/*MEM_LOAD_RETIRED_L3_MISS*/
			%s ,/*RDTSC*/
			%s ,/*Referencecycles*/
			%s ,/*UOPS_DISPATCHED_PORT_PORT_0*/
			%s ,/*UOPS_DISPATCHED_PORT_PORT_1*/ 
			%s ,/*UOPS_DISPATCHED_PORT_PORT_2*/
			%s ,/*UOPS_DISPATCHED_PORT_PORT_3*/
			%s ,/*UOPS_DISPATCHED_PORT_PORT_4*/ 
			%s ,/*UOPS_DISPATCHED_PORT_PORT_5*/
			%s ,/*UOPS_DISPATCHED_PORT_PORT_6*/
			%s ,/*UOPS_DISPATCHED_PORT_PORT_7*/  
			%s ,/*UOPS_EXECUTED_THREAD*/
			%s /*UOPS_ISSUED_ANY*/
			
			)"""
			
			
			# Adding Values
			
			val = (
				data["Instruction"], 
				data["InstructionID"], 
				data["BR_INST_RETIRED.ALL_BRANCHES"], 
				data["BR_MISP_RETIRED.ALL_BRANCHES"], 
				data["Corecycles"], 
				data["Instructionsretired"], 
				data["MEM_LOAD_RETIRED.L1_HIT"], 
				data["MEM_LOAD_RETIRED.L1_MISS"], 
				data["MEM_LOAD_RETIRED.L2_HIT"], 
				data["MEM_LOAD_RETIRED.L2_MISS"], 
				data["MEM_LOAD_RETIRED.L3_HIT"], 
				data["MEM_LOAD_RETIRED.L3_MISS"], 
				data["RDTSC"], 
				data["Referencecycles"], 
				data["UOPS_DISPATCHED_PORT.PORT_0"], 
				data["UOPS_DISPATCHED_PORT.PORT_1"], 
				data["UOPS_DISPATCHED_PORT.PORT_2"], 
				data["UOPS_DISPATCHED_PORT.PORT_3"], 
				data["UOPS_DISPATCHED_PORT.PORT_4"], 
				data["UOPS_DISPATCHED_PORT.PORT_5"], 
				data["UOPS_DISPATCHED_PORT.PORT_6"], 
				data["UOPS_DISPATCHED_PORT.PORT_7"], 
				data["UOPS_EXECUTED.THREAD"], 
				data["UOPS_ISSUED.ANY"]
			
			)
			
			
			
			mycursor.execute(sql, val)
			
			mydb.commit()
			
			print("Instruction ID : "+ str(instructionID))
			instructionID = instructionID + 1
			print(mycursor.rowcount, "record inserted.")
			EachElementJson = ""

