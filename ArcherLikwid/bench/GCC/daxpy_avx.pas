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

FUNC daxpy_avx
{
vmovaps ymm7, [rip+SCALAR]



LOOP .loop 24 GPR6 {
vmulpd    ymm1, ymm7, [STR0 + GPR1*8]
vaddpd    ymm1, ymm1, [STR1 + GPR1*8]
vmulpd    ymm2, ymm7, [STR0 + GPR1*8+32]
vaddpd    ymm2, ymm2, [STR1 + GPR1*8+32]
vmovaps    [STR1 + GPR1*8], ymm1
vmovaps    [STR1 + GPR1*8+32], ymm2
vmulpd    ymm3, ymm7, [STR0 + GPR1*8+64]
vaddpd    ymm3, ymm3, [STR1 + GPR1*8+64]
vmulpd    ymm4, ymm7, [STR0 + GPR1*8+96]
vaddpd    ymm4, ymm4, [STR1 + GPR1*8+96]
vmovaps    [STR1 + GPR1*8+64], ymm3
vmovaps    [STR1 + GPR1*8+96], ymm4
vmulpd    ymm5, ymm7, [STR0 + GPR1*8+128]
vaddpd    ymm5, ymm5, [STR1 + GPR1*8+128]
vmulpd    ymm6, ymm7, [STR0 + GPR1*8+160]
vaddpd    ymm6, ymm6, [STR1 + GPR1*8+160]
vmovaps    [STR1 + GPR1*8+128], ymm5
vmovaps    [STR1 + GPR1*8+160], ymm6


}

}

STOP LOCAL

