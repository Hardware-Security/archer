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
.global ddot_sse
.type ddot_sse, @function
ddot_sse :
push rbp
mov rbp, rsp
push rbx
push r12
push r13
push r14
push r15
xorpd xmm0, xmm0
xorpd xmm5, xmm5
xorpd xmm6, xmm6
xorpd xmm7, xmm7
xor   rax, rax
.align 16
1:
movaps xmm1, [rsi + rax * 8]
mulpd xmm1, [rdx + rax * 8]
addpd xmm0, xmm1
movaps xmm2, [rsi + rax * 8 + 16]
mulpd xmm2, [rdx + rax * 8 + 16]
addpd xmm5, xmm2
movaps xmm3, [rsi + rax * 8 + 32]
mulpd xmm3, [rdx + rax * 8 + 32]
addpd xmm6, xmm3
movaps xmm4, [rsi + rax * 8 + 48]
mulpd xmm4, [rdx + rax * 8 + 48]
addpd xmm7, xmm4
add rax, 8
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
.size ddot_sse, .-ddot_sse


