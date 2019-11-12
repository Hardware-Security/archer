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
.global peakflops_avx
.type peakflops_avx, @function
peakflops_avx :
push rbp
mov rbp, rsp
push rbx
push r12
push r13
push r14
push r15
vmovaps ymm1, [rip+SCALAR]
vmovaps ymm2, [rip+SCALAR]
vmovaps ymm3, [rip+SCALAR]
vmovaps ymm4, [rip+SCALAR]
vmovaps ymm5, [rip+SCALAR]
vmovaps ymm6, [rip+SCALAR]
vmovaps ymm7, [rip+SCALAR]
vmovaps ymm8, [rip+SCALAR]
vmovaps ymm9, [rip+SCALAR]
.align 32
xor   rax, rax
.align 16
1:
vmovapd ymm1, [rsi + rax * 8 ]
vaddpd ymm2, ymm2, ymm1
vmulpd ymm3, ymm3, ymm1
vaddpd ymm4, ymm4, ymm1
vmulpd ymm5, ymm5, ymm1
vaddpd ymm6, ymm6, ymm1
vmulpd ymm7, ymm7, ymm1
vaddpd ymm8, ymm8, ymm1
vmulpd ymm9, ymm9, ymm1
add rax, 4
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
.size peakflops_avx, .-peakflops_avx


