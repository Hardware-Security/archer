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

FUNC stream_sp_mem_avx512
{
vmovaps zmm1, [rip+SCALAR]



LOOP .loop 64 GPR6 {
vmovaps   zmm2, [STR1 + GPR1*4]
vmovaps   zmm3, [STR1 + GPR1*4+64]
vmovaps   zmm4, [STR1 + GPR1*4+128]
vmovaps   zmm5, [STR1 + GPR1*4+192]
vmulps    zmm2, zmm2, zmm1
vaddps    zmm2, zmm2, [STR2 + GPR1*4]
vmulps    zmm3, zmm3, zmm1
vaddps    zmm3, zmm3, [STR2 + GPR1*4+64]
vmulps    zmm4, zmm4, zmm1
vaddps    zmm4, zmm4, [STR2 + GPR1*4+128]
vmulps    zmm5, zmm5, zmm1
vaddps    zmm5, zmm5, [STR2 + GPR1*4+192]
vmovntps    [STR0 + GPR1*4], zmm2
vmovntps    [STR0 + GPR1*4+64], zmm3
vmovntps    [STR0 + GPR1*4+128], zmm4
vmovntps    [STR0 + GPR1*4+192], zmm5

}

}

STOP LOCAL

