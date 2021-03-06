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

FUNC stream_sp_mem_avx512_fma
{
vmovaps zmm1, [rip+SCALAR]



LOOP .loop 64 GPR6 {
vmovaps   zmm2, [STR1 + GPR1*4]
vmovaps   zmm3, [STR1 + GPR1*4+64]
vmovaps   zmm4, [STR1 + GPR1*4+128]
vmovaps   zmm5, [STR1 + GPR1*4+192]
vfmadd213ps zmm2, zmm1, [STR2 + GPR1*4]
vfmadd213ps zmm3, zmm1, [STR2 + GPR1*4+64]
vfmadd213ps zmm4, zmm1, [STR2 + GPR1*4+128]
vfmadd213ps zmm5, zmm1, [STR2 + GPR1*4+192]
vmovntps   [STR0 + GPR1*4], zmm2
vmovntps   [STR0 + GPR1*4+64], zmm3
vmovntps   [STR0 + GPR1*4+128], zmm4
vmovntps   [STR0 + GPR1*4+192], zmm5

}

}

STOP LOCAL

