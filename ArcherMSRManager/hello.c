#include<linux/init.h>
#include<linux/module.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("maK");
typedef union _Detail_Packet {

	struct
	{
		long unsigned int RES_RDMSR;
		long unsigned int RES_RDTSCP;
		long unsigned int ECX_INDEX;
		long unsigned int FAULT_BITMASK;
		long unsigned int CORE_ID;
		long unsigned int PACKET_Type;
		long unsigned int CRC32_SIGN;

	}Fields;


}Detail_Packet, * PDetail_Packet;

void * AddressOfBuffer;


void LogManager(PDetail_Packet MyPacket_)
{
	__asm__ volatile("sti\n\t");
	printk("Size of packet = %d\n", sizeof(Detail_Packet));
	// Go to first arg of packet	
	PDetail_Packet MyPacket = (PDetail_Packet)AddressOfBuffer; 
	//MyPacket->Fields.CORE_ID= KeGetCurrentProcessorNumberEx(NULL);
	//functionSTI();
	// show the result
	printk("RDMSR RESULT = 0x%lx , RDTSCP RESULT = 0x%lx , RCX INDEX = 0x%lx , FAULT_BITMASK = 0x%lx, CORE_ID = 0x%lx , PACKET_TYPE = 0x%lx , CRC_SIGN = 0x%lx \n",
		MyPacket->Fields.RES_RDMSR,
		MyPacket->Fields.RES_RDTSCP, 
		MyPacket->Fields.ECX_INDEX, 
		MyPacket->Fields.FAULT_BITMASK,
		MyPacket->Fields.CORE_ID,
		MyPacket->Fields.PACKET_Type,
		MyPacket->Fields.CRC32_SIGN);
	
}

//-----------------------------------------------------
int my_module(void)
{

int i=0;
const long unsigned int CountOfBruteForce = 23;
const long unsigned int StartMSRFrom = 0xc0000080;
long unsigned int addressbuffer ;

AddressOfBuffer = vmalloc(sizeof(Detail_Packet));

printk("AddressOfBuffer=%llx\n",AddressOfBuffer);
int *p = AddressOfBuffer;
for ( i=0; i<7; i++)
    printk("%llx\n", p[i]);

//---------------------------------------------------------------



__asm__ volatile(

// Save state frame
"push %%rax\n\t"
"push %%rbx\n\t" 
"push %%rcx\n\t" 
"push %%rdx\n\t" 
"push %%rdi\n\t" 
"push %%rsi\n\t" 
"push %%r8\n\t" 
"push %%r9\n\t"
"push %%r10\n\t" 
"push %%r11\n\t" 
"push %%r12\n\t" 
"push %%r13\n\t" 
"push %%r14\n\t" 
"push %%r15\n\t"
// end of save state frame

//====================================================================================

"xor %%r10, %%r10\n\t"
"xor %%r11, %%r11\n\t"
"xor %%r12, %%r12\n\t"
"xor %%r13, %%r13\n\t"
"xor %%r14, %%r14\n\t"
"xor %%r15, %%r15\n\t"

//mov CountOfBruteForce to r8 	
"movq %[CountOfBruteForce], %%r8\n\t" 


//mov StartMSRFrom to R10 
//r10 is for last msr rcx
"movq %[StartMSRFrom], %%r10\n\t"

//mov  AddressOfBuffer to r9	
"movq %[AddressOfBuffer], %%r12\n\t"

//============================== CLEAR REGISTERS ===================================

// clear the msr general purpose registers
"xor %%rax, %%rax\n\t"
"xor %%rdx, %%rdx\n\t"  
"xor %%rcx, %%rcx\n\t"

//=====================================================================================



//------------------------------------------------

"_MSRRead:\n\t"


"cli\n\t"
//=======================================================================================

//=======================================================================================
"mov %%r12, %%r9\n\t"

//=======================================================================================

// Clear the modified registers once again
"xor %%rax, %%rax\n\t"
"xor %%rdx, %%rdx\n\t"
"xor %%r13, %%r13\n\t"
"xor %%r14, %%r14\n\t"
"xor %%r15, %%r15\n\t"

//====================== INSTRUCTION DATA EXTRACTION =====================================

 "RDTSCP\n\t"
 //save last rdtscp rax into r13
 "mov %%rax,%%r13\n\t"

// Start of RDMSR area
 //store last rdmsr rcx into r10
 "mov %%r10,%%rcx\n\t"

"RDMSR\n\t"

//save last rdmsr rdx into r14
 "mov %%rdx,%%r14\n\t"
//save last rdmsr rax into r15
 "mov %%rax,%%r15\n\t"
 "RDTSCP\n\t"
// End of RDMSR area
//======================== CALCULATE SUB OF RDTSCP =======================================

//calculate delta of two rdtscp
"sub %%r13, %%rax\n\t"

//========================= APPENDING ====================================================

// Append r14:r15(rdmsr)
"SHL $32, %%r14\n\t"
"mov $0x0FFFFFFFF, %%r11\n\t"
"and %%r11, %%r15\n\t"
"or %%r15, %%r14\n\t"

//====================== SAVE RESULT INTO BUFFER =========================================

//save RDMSR RESULT INTO FIRST ARG OF STRUCT
"movq %%r14, (%%r9)\n\t"

//Increment r9 (Buffer Address by 8) in order to have an index to save into the buffer
"add $0x08,%%r9\n\t"

//SAVE RDTSCP RESULT INTO SECOND OF STRUCT
"movq %%rax, (%%r9)\n\t"


//Increment r9 (Buffer Address by 8) in order to have an index to save into the buffer
"add $0x08, %%r9\n\t"

//SAVE rcx of rdfmsr(r10) into THIRD OF STRUCT
"movq %%r10, (%%r9)\n\t"

//Increment r9 (Buffer Address by 8) in order to have an index to save into the buffer
"add $0x08, %%r9\n\t"

//IN ORDER TO MAKE FREE SPACE FOR FAULT_BITMASK
"movq $0, (%%r9)\n\t"
"add $0x08, %%r9\n\t"

//SAVE core id into fifth
"movq $0, (%%r9)\n\t"
"add $0x08, %%r9\n\t"

//SAVE PACKET_TYPE INTO sixth ARG OF STRUCT
"movq $0x01, (%%r9)\n\t"
"add $0x08, %%r9\n\t"

//IN ORDER TO MAKE FREE SPACE FOR CRC32_SIGN
"movq $0, (%%r9)\n\t"
"add $0x08, %%r9\n\t"

//======================== PACKET IS READY AND CALL PACKET FUNC ================================
"push %%rax\n\t"
"push %%rbx\n\t" 
"push %%rcx\n\t" 
"push %%rdx\n\t" 
"push %%rdi\n\t" 
"push %%rsi\n\t" 
"push %%r8\n\t" 
"push %%r9\n\t"
"push %%r10\n\t" 
"push %%r11\n\t" 
"push %%r12\n\t" 
"push %%r13\n\t" 
"push %%r14\n\t" 
"push %%r15\n\t"

//		fastcall????????????????
//"mov %%r10,%%rcx\n\t"

"CALL LogManager\n\t"
"pop %%r15\n\t"
"pop %%r14\n\t" 
"pop %%r13\n\t" 
"pop %%r12\n\t" 
"pop %%r11\n\t" 
"pop %%r10\n\t" 
"pop %%r9\n\t"
"pop %%r8\n\t" 
"pop %%rsi\n\t" 
"pop %%rdi\n\t" 
"pop %%rdx\n\t" 
"pop %%rcx\n\t" 
"pop %%rbx\n\t" 
"pop %%rax\n\t"

//======================== INC DeC OF COUNTER =================================================

//Increment the r10 for the msr index
"inc %%r10\n\t"

//Decrement counter by one 
"dec %%r8\n\t"

"cmp $0x0, %%r8\n\t"

"JNZ _MSRRead\n\t"

//-------------------------------------------------
"pop %%r15\n\t"
"pop %%r14\n\t" 
"pop %%r13\n\t" 
"pop %%r12\n\t" 
"pop %%r11\n\t" 
"pop %%r10\n\t" 
"pop %%r9\n\t"
"pop %%r8\n\t" 
"pop %%rsi\n\t" 
"pop %%rdi\n\t" 
"pop %%rdx\n\t" 
"pop %%rcx\n\t" 
"pop %%rbx\n\t" 
"pop %%rax\n\t"

:[buffer]"+r" (addressbuffer): [AddressOfBuffer]"r" (AddressOfBuffer), [CountOfBruteForce]"r" (CountOfBruteForce) ,[StartMSRFrom]"r" (StartMSRFrom) );

printk("addressbuffer = %llx\n",addressbuffer);

return 0;
}
static int hello_init(void){
	printk(KERN_ALERT "Hello world!\n");
	return 0;
}

static void hello_exit(void){
	printk(KERN_ALERT "Goodbye cruel world\n");
}

module_init(my_module);
module_exit(hello_exit);

