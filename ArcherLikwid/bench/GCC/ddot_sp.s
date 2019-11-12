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
.global ddot_sp
.type ddot_sp, @function
ddot_sp :
push rbp
mov rbp, rsp
push rbx
push r12
push r13
push r14
push r15
xorps xmm0, xmm0
xorps xmm5, xmm5
xorps xmm6, xmm6
xorps xmm7, xmm7
xor   rax, rax
.align 16
1:
movss xmm1, [rsi + rax * 4]
mulss xmm1, [rdx + rax * 4]
addss xmm0, xmm1
movss xmm2, [rsi + rax * 4 + 4]
mulss xmm2, [rdx + rax * 4 + 4]
addss xmm5, xmm2
movss xmm3, [rsi + rax * 4 + 8]
mulss xmm3, [rdx + rax * 4 + 8]
addss xmm6, xmm3
movss xmm4, [rsi + rax * 4 + 12]
mulss xmm4, [rdx + rax * 4 + 12]
addss xmm7, xmm4
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
.size ddot_sp, .-ddot_sp


