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

FUNC sum_avx
{
vxorpd ymm1, ymm1, ymm1
vmovapd ymm2, ymm1
vmovapd ymm3, ymm1
vmovapd ymm4, ymm1
vmovapd ymm5, ymm1
vmovapd ymm6, ymm1
vmovapd ymm7, ymm1
vmovapd ymm8, ymm1



LOOP .loop 32 GPR6 {
vaddpd    ymm1, ymm1, [STR0 + GPR1 * 8]
vaddpd    ymm2, ymm2, [STR0 + GPR1 * 8 + 32]
vaddpd    ymm3, ymm3, [STR0 + GPR1 * 8 + 64]
vaddpd    ymm4, ymm4, [STR0 + GPR1 * 8 + 96]
vaddpd    ymm5, ymm5, [STR0 + GPR1 * 8 + 128]
vaddpd    ymm6, ymm6, [STR0 + GPR1 * 8 + 160]
vaddpd    ymm7, ymm7, [STR0 + GPR1 * 8 + 192]
vaddpd    ymm8, ymm8, [STR0 + GPR1 * 8 + 224]



}

}

STOP LOCAL

