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

FUNC stream_sp
{
movss FPR9, [rip+SCALAR]



LOOP .loop 8 GPR6 {
movss    FPR1, [STR1 + GPR1*4]
movss    FPR2, [STR1 + GPR1*4+4]
movss    FPR3, [STR1 + GPR1*4+8]
movss    FPR4, [STR1 + GPR1*4+12]
movss    FPR5, [STR1 + GPR1*4+16]
movss    FPR6, [STR1 + GPR1*4+20]
movss    FPR7, [STR1 + GPR1*4+24]
movss    FPR8, [STR1 + GPR1*4+28]
mulss    FPR1, FPR9
addss    FPR1, [STR2 + GPR1*4]
mulss    FPR2, FPR9
addss    FPR2, [STR2 + GPR1*4+4]
mulss    FPR3, FPR9
addss    FPR3, [STR2 + GPR1*4+8]
mulss    FPR4, FPR9
addss    FPR4, [STR2 + GPR1*4+12]
mulss    FPR5, FPR9
addss    FPR5, [STR2 + GPR1*4+16]
mulss    FPR6, FPR9
addss    FPR6, [STR2 + GPR1*4+20]
mulss    FPR7, FPR9
addss    FPR7, [STR2 + GPR1*4+24]
mulss    FPR8, FPR9
addss    FPR8, [STR2 + GPR1*4+28]
movss    [STR0 + GPR1*4]   , FPR1
movss    [STR0 + GPR1*4+4] , FPR2
movss    [STR0 + GPR1*4+8] , FPR3
movss    [STR0 + GPR1*4+12], FPR4
movss    [STR0 + GPR1*4+16], FPR5
movss    [STR0 + GPR1*4+20], FPR6
movss    [STR0 + GPR1*4+24], FPR7
movss    [STR0 + GPR1*4+28], FPR8


}

}

STOP LOCAL

