.intel_syntax noprefix
.data
.align 64
SCALAR:
.double 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
.align 64
SSCALAR:
.single 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
.align 64
ISCALAR:
.int 1, 1
.align 16
OMM:
.int 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
.align 16
IOMM:
.int 0,16,32,48,64,80,96,128,144,160,176,192,208,224,240,256
.align 16
TOMM:
.int 0,2,4,6,16,18,20,22,32,34,36,38,48,50,52,54
.text
.global ddot_avx512
.type ddot_avx512, @function
ddot_avx512 :
push rbp
mov rbp, rsp
push rbx
push r12
push r13
push r14
push r15
xor   rax, rax
.align 16
1:
vmovapd zmm1, [rsi + rax * 8]
vmulpd zmm1, zmm1, [rdx + rax * 8]
vaddpd zmm0, zmm0, zmm1
vmovapd zmm2, [rsi + rax * 8 + 64]
vmulpd zmm2, zmm2, [rdx + rax * 8 + 64]
vaddpd zmm5, zmm5, zmm2
vmovapd zmm3, [rsi + rax * 8 + 128]
vmulpd zmm3, zmm3, [rdx + rax * 8 + 128]
vaddpd zmm6, zmm6, zmm3
vmovapd zmm4, [rsi + rax * 8 + 192]
vmulpd zmm4, zmm4, [rdx + rax * 8 + 192]
vaddpd zmm7, zmm7, zmm4
add rax, 32
cmp rax, rdi
jl 1b

pop r15
pop r14
pop r13
pop r12
pop rbx
mov  rsp, rbp
pop rbp
ret
.size ddot_avx512, .-ddot_avx512


