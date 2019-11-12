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
.global ddot_avx
.type ddot_avx, @function
ddot_avx :
push rbp
mov rbp, rsp
push rbx
push r12
push r13
push r14
push r15
vxorpd ymm0, ymm0, ymm0
vxorpd ymm5, ymm5, ymm5
vxorpd ymm6, ymm6, ymm6
vxorpd ymm7, ymm7, ymm7
xor   rax, rax
.align 16
1:
vmovaps ymm1, [rsi + rax * 8]
vmulpd ymm1, ymm1, [rdx + rax * 8]
vaddpd ymm0, ymm0, ymm1
vmovaps ymm2, [rsi + rax * 8 + 32]
vmulpd ymm2, ymm2, [rdx + rax * 8 + 32]
vaddpd ymm5, ymm5, ymm2
vmovaps ymm3, [rsi + rax * 8 + 64]
vmulpd ymm3, ymm3, [rdx + rax * 8 + 64]
vaddpd ymm6, ymm6, ymm3
vmovaps ymm4, [rsi + rax * 8 + 96]
vmulpd ymm4, ymm4, [rdx + rax * 8 + 96]
vaddpd ymm7, ymm7, ymm4
add rax, 16
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
.size ddot_avx, .-ddot_avx


