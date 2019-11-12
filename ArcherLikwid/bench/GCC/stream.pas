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

FUNC stream
{
movss FPR5, [rip+SCALAR]



LOOP .loop 4 GPR6 {
movsd    FPR1, [STR1 + GPR1*8]
movsd    FPR2, [STR1 + GPR1*8+8]
movsd    FPR3, [STR1 + GPR1*8+16]
movsd    FPR4, [STR1 + GPR1*8+24]
mulsd    FPR1, FPR5
addsd    FPR1, [STR2 + GPR1*8]
mulsd    FPR2, FPR5
addsd    FPR2, [STR2 + GPR1*8+8]
mulsd    FPR3, FPR5
addsd    FPR3, [STR2 + GPR1*8+16]
mulsd    FPR4, FPR5
addsd    FPR4, [STR2 + GPR1*8+24]
movsd    [STR0 + GPR1*8]   , FPR1
movsd    [STR0 + GPR1*8+8] , FPR2
movsd    [STR0 + GPR1*8+16], FPR3
movsd    [STR0 + GPR1*8+24], FPR4


}

}

STOP LOCAL

