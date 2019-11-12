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

FUNC ddot_avx
{
vxorpd ymm0, ymm0, ymm0
vxorpd ymm5, ymm5, ymm5
vxorpd ymm6, ymm6, ymm6
vxorpd ymm7, ymm7, ymm7



LOOP .loop 16 GPR6 {
vmovaps ymm1,       [STR0 + GPR1 * 8]
vmulpd  ymm1, ymm1, [STR1 + GPR1 * 8]
vaddpd  ymm0, ymm0, ymm1
vmovaps ymm2,       [STR0 + GPR1 * 8 + 32]
vmulpd  ymm2, ymm2, [STR1 + GPR1 * 8 + 32]
vaddpd  ymm5, ymm5, ymm2
vmovaps ymm3,       [STR0 + GPR1 * 8 + 64]
vmulpd  ymm3, ymm3, [STR1 + GPR1 * 8 + 64]
vaddpd  ymm6, ymm6, ymm3
vmovaps ymm4,       [STR0 + GPR1 * 8 + 96]
vmulpd  ymm4, ymm4, [STR1 + GPR1 * 8 + 96]
vaddpd  ymm7, ymm7, ymm4

}

}

STOP LOCAL

