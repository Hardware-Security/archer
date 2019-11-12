#define STR0 ARG2
#define STR1 ARG3
#define STR2 ARG4
#define STR3 ARG5 
#define STR4 ARG6 

#define STR5 GPR9 
#define STR6 GPR10 
#define STR7 GPR11 
#define STR8 GPR12 
#define STR9 GPR13 
#define STR10 GPR14 


DEFINE DOUBLE SCALAR  1.0
DEFINE SINGLE SSCALAR  1.0
DEFINE INT ISCALAR  1
DEFINE INT OMM  0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
DEFINE INT IOMM  0,16,32,48,64,80,96,128,144,160,176,192,208,224,240,256
DEFINE INT TOMM  0,2,4,6,16,18,20,22,32,34,36,38,48,50,52,54

START LOCAL

FUNC sum_sse
{
xorpd FPR1, FPR1
movapd FPR2, FPR1
movapd FPR3, FPR1
movapd FPR4, FPR1
movapd FPR5, FPR1
movapd FPR6, FPR1
movapd FPR7, FPR1
movapd FPR8, FPR1



LOOP .loop 16 GPR6 {
addpd    FPR1, [STR0 + GPR1 * 8]
addpd    FPR2, [STR0 + GPR1 * 8 + 16]
addpd    FPR3, [STR0 + GPR1 * 8 + 32]
addpd    FPR4, [STR0 + GPR1 * 8 + 48]
addpd    FPR5, [STR0 + GPR1 * 8 + 64]
addpd    FPR6, [STR0 + GPR1 * 8 + 80]
addpd    FPR7, [STR0 + GPR1 * 8 + 96]
addpd    FPR8, [STR0 + GPR1 * 8 + 112]



}

}

STOP LOCAL

