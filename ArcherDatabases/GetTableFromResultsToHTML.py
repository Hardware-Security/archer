import mysql.connector

def query_mysql(query):
	cnx = mysql.connector.connect(user='UserHere', password='PasswordHere',
								  host='IpHerre',port='3306',
								  database='DbNameHere',charset="utf8", use_unicode = True)
	cursor = cnx.cursor()
	cursor.execute(query)
	#get header and rows
	header = [i[0] for i in cursor.description]
	rows = [list(i) for i in cursor.fetchall()]
	#append header to rows
	rows.insert(0,header)
	cursor.close()
	cnx.close()
	return rows

#take list of lists as argument	
def nlist_to_html(list2d):
	#bold header
	htable=u'<table border="1" bordercolor=000000 cellspacing="0" cellpadding="1" style="table-layout:fixed;vertical-align:bottom;font-size:13px;font-family:verdana,sans,sans-serif;border-collapse:collapse;border:1px solid rgb(130,130,130)" >'
	list2d[0] = [u'<b>' + i + u'</b>' for i in list2d[0]] 
	for row in list2d:
		newrow = u'<tr>' 
		newrow += u'<td align="left" style="padding:1px 4px">'+unicode(row[0])+u'</td>'
		row.remove(row[0])
		newrow = newrow + ''.join([u'<td align="right" style="padding:1px 4px">' + unicode(x) + u'</td>' for x in row])  
		newrow += '</tr>' 
		htable+= newrow
	htable += '</table>'
	return htable
	


def sql_html(query):
	return nlist_to_html(query_mysql(query))
	
#usage example
query = """

  select CONCAT(Mnemonic, ' ' , FirstOperand , ' ,' , SecondOperand , ', ', ThirdOperand) as Disasm,
  ARITH_DIVIDER_ACTIVE ,
    ARITH_DIVIDER_COUNT  ,
    AVX_DP_MFLOP_per_s  ,
    AVX_SP_MFLOP_per_s  ,
    Avg_stall_duration_cycles  ,
    Avg_divide_unit_usage_duration  ,
    Avg_recovery_duration  ,
    BR_INST_RETIRED_ALL_BRANCHES  ,
    BR_MISP_RETIRED_ALL_BRANCHES  ,
    Back_End_percent  ,
    Branch_misprediction_rate  ,
    Branch_misprediction_ratio  ,
    Branch_rate  ,
    CPI  ,
    CPU_CLK_UNHALTED_CORE  ,
    CPU_CLK_UNHALTED_REF  ,
    CPU_CLOCK_UNHALTED_TOTAL_CYCLES  ,
    CYCLE_ACTIVITY_CYCLES_L1D_PENDING  ,
    CYCLE_ACTIVITY_CYCLES_L2_PENDING  ,
    CYCLE_ACTIVITY_CYCLES_LDM_PENDING  ,
    CYCLE_ACTIVITY_CYCLES_NO_EXECUTE  ,
    CYCLE_ACTIVITY_STALLS_L1D_PENDING  ,
    CYCLE_ACTIVITY_STALLS_L2_PENDING  ,
    CYCLE_ACTIVITY_STALLS_LDM_PENDING  ,
    CYCLE_ACTIVITY_STALLS_TOTAL  ,
    Clock_MHz  ,
    Cycles_without_execution_percent  ,
    Cycles_without_execution_due_to_L1D_percent ,
    Cycles_without_execution_due_to_L2_percent ,
    Cycles_without_execution_due_to_memory_loads_percent  ,
    DP_MFLOP_per_s  ,
    DTLB_LOAD_MISSES_CAUSES_A_WALK  ,
    DTLB_LOAD_MISSES_WALK_ACTIVE  ,
    DTLB_STORE_MISSES_CAUSES_A_WALK  ,
    DTLB_STORE_MISSES_WALK_ACTIVE  ,
    Energy_DRAM_J  ,
    Energy_PP0_J  ,
    Energy_PP1_J  ,
    Energy_J  ,
    Executed_UOPs  ,
    Execution_stall_rate_percent  ,
    FP_ARITH_INST_RETIRED_128B_PACKED_DOUBLE  ,
    FP_ARITH_INST_RETIRED_128B_PACKED_SINGLE  ,
    FP_ARITH_INST_RETIRED_256B_PACKED_DOUBLE  ,
    FP_ARITH_INST_RETIRED_256B_PACKED_SINGLE  ,
    FP_ARITH_INST_RETIRED_SCALAR_DOUBLE  ,
    FP_ARITH_INST_RETIRED_SCALAR_SINGLE  ,
    Fetch_Bubbles  ,
    FirstOperand  ,
    Front_End_percent  ,
    ICACHE_64B_IFTAG_ALL  ,
    ICACHE_64B_IFTAG_MISS  ,
    ICACHE_64B_IFTAG_STALL  ,
    IDQ_UOPS_NOT_DELIVERED_CORE  ,
    INSTR_RETIRED_ANY  ,
    INT_MISC_RECOVERY_COUNT  ,
    INT_MISC_RECOVERY_CYCLES  ,
    IPC  ,
    ITLB_MISSES_CAUSES_A_WALK  ,
    ITLB_MISSES_WALK_ACTIVE  ,
    InstructionID  ,
    Instructions_per_branch  ,
    Issued_UOPs  ,
    L1_DTLB_load_miss_duration_Cyc  ,
    L1_DTLB_load_miss_rate  ,
    L1_DTLB_load_misses  ,
    L1_DTLB_store_miss_duration_Cyc  ,
    L1_DTLB_store_miss_rate  ,
    L1_DTLB_store_misses  ,
    L1_ITLB_miss_duration_Cyc  ,
    L1_ITLB_miss_rate  ,
    L1_ITLB_misses  ,
    L1D_M_EVICT  ,
    L1D_REPLACEMENT  ,
    L1I_miss_rate  ,
    L1I_miss_ratio  ,
    L1I_request_rate  ,
    L1I_stall_rate  ,
    L1I_stalls  ,
    L2_bandwidth_MBytes_per_s  ,
    L2_data_volume_GBytes  ,
    L2_miss_rate  ,
    L2_miss_ratio  ,
    L2_request_rate ,
    L2D_evict_bandwidth_MBytes_per_s  ,
    L2D_evict_data_volume_GBytes  ,
    L2D_load_bandwidth_MBytes_per_s ,
    L2D_load_data_volume_GBytes  ,
    L2_LINES_IN_ALL  ,
    L2_RQSTS_MISS  ,
    L2_TRANS_ALL_REQUESTS  ,
    L2_TRANS_L2_WB  ,
    L3_bandwidth_MBytes_per_s  ,
    L3_data_volume_GBytes  ,
    L3_evict_bandwidth_MBytes_per_s  ,
    L3_evict_data_volume_GBytes  ,
    L3_load_bandwidth_MBytes_per_s  ,
    L3_load_data_volume_GBytes  ,
    L3_miss_rate  ,
    L3_miss_ratio  ,
    L3_request_rate  ,
    Load_to_store_ratio  ,
    Local_LLC_false_sharing_MByte  ,
    Local_LLC_false_sharing_rate  ,
    MEM_INST_RETIRED_ALL  ,
    MEM_INST_RETIRED_ALL_LOADS  ,
    MEM_INST_RETIRED_ALL_STORES  ,
    MEM_LOAD_L3_HIT_RETIRED_XSNP_HITM ,
    MEM_LOAD_RETIRED_L3_HIT  ,
    MEM_LOAD_RETIRED_L3_MISS  ,
    Memory_bandwidth_MBytes_per_s ,
    Memory_data_volume_GBytes  ,
    Memory_evict_bandwidth_MBytes_per_s ,
    Memory_evict_data_volume_GBytes  ,
    Memory_load_bandwidth_MBytes_per_s ,
    Memory_load_data_volume_GBytes ,
    Mnemonic  ,
    Number_of_divide_ops  ,
    Operational_intensity ,
    PWR_DRAM_ENERGY  ,
    PWR_PKG_ENERGY  ,
    PWR_PP0_ENERGY  ,
    PWR_PP1_ENERGY  ,
    Packed_DP_MFLOP_per_s  ,
    Packed_MUOPS_per_s  ,
    Packed_SP_MFLOP_per_s  ,
    Port0_usage_ratio  ,
    Port1_usage_ratio  ,
    Port2_usage_ratio  ,
    Port3_usage_ratio  ,
    Port4_usage_ratio  ,
    Port5_usage_ratio  ,
    Port6_usage_ratio  ,
    Port7_usage_ratio  ,
    Power_DRAM_W ,
    Power_PP0_W  ,
    Power_PP1_W  ,
    Power_W  ,
    Recovery_Bubbles  ,
    Retired_UOPs  ,
    Retiring_percent  ,
    Runtime_RDTSC_s  ,
    Runtime_unhalted_s  ,
    SP_MFLOP_per_s  ,
    Scalar_MUOPS_per_s ,
    SecondOperand   ,
    Slots_Retired  ,
    Speculation_percent  ,
    Stalls_caused_by_L1D_misses_percent  ,
    Stalls_caused_by_L1D_misses_rate_percent  ,
    Stalls_caused_by_L2_misses_percent  ,
    Stalls_caused_by_L2_misses_rate_percent  ,
    Stalls_caused_by_memory_loads_percent  ,
    Stalls_caused_by_memory_loads_rate_percent  ,
    TEMP_CORE  ,
    Temperature_C  ,
    ThirdOperand   ,
    Total_Slots  ,
    Total_execution_stalls  ,
    UNCORE_CLOCK  ,
    UOPS_DISPATCHED_PORT_PORT_0  ,
    UOPS_DISPATCHED_PORT_PORT_1  ,
    UOPS_DISPATCHED_PORT_PORT_2  ,
    UOPS_DISPATCHED_PORT_PORT_3 ,
    UOPS_EXECUTED_STALL_CYCLES  ,
    UOPS_EXECUTED_THREAD  ,
    UOPS_EXECUTED_USED_CYCLES ,
    UOPS_ISSUED_ANY  ,
    UOPS_ISSUED_STALL_CYCLES  ,
    UOPS_ISSUED_USED_CYCLES  ,
    UOPS_RETIRED_ALL  ,
    UOPS_RETIRED_RETIRE_SLOTS ,
    UOPS_RETIRED_STALL_CYCLES ,
    UOPS_RETIRED_USED_CYCLES ,
    Uncore_Clock_MHz ,
    Unused_cycles_ratio_percent ,
    Used_cycles_ratio_percent ,
    Vectorization_ratio ,
    instruction  
	from PerformanceCounterResults;



"""
print sql_html(query)
