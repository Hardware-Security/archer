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

FUNC daxpy_mem_avx_fma
{
vmovaps ymm7, [rip+SCALAR]



LOOP .loop 16 GPR6 {
vmovaps    ymm1, [STR0 + GPR1*8]
vmovaps    ymm2, [STR0 + GPR1*8+32]
vmovaps    ymm3, [STR0 + GPR1*8+64]
vmovaps    ymm4, [STR0 + GPR1*8+96]
vfmadd213pd ymm1, ymm7, [STR1 + GPR1*8]
vfmadd213pd ymm2, ymm7, [STR1 + GPR1*8+32]
vfmadd213pd ymm3, ymm7, [STR1 + GPR1*8+64]
vfmadd213pd ymm4, ymm7, [STR1 + GPR1*8+96]
vmovntps    [STR1 + GPR1*8], ymm1
vmovntps    [STR1 + GPR1*8+32], ymm2
vmovntps    [STR1 + GPR1*8+64], ymm3
vmovntps    [STR1 + GPR1*8+96], ymm4

}

}

STOP LOCAL

