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
.global triad_sp
.type triad_sp, @function
triad_sp :
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
movss xmm0, [rdx + rax*4]
movss xmm1, [rdx + rax*4 + 4]
movss xmm2, [rdx + rax*4 + 8]
movss xmm3, [rdx + rax*4 + 12]
mulss xmm0, [rcx + rax*4]
addss xmm0, [r8 + rax*4]
movss xmm4, [rdx + rax*4 + 16]
mulss xmm1, [rcx + rax*4 + 4]
addss xmm1, [r8 + rax*4 + 4]
movss xmm5, [rdx + rax*4 + 20]
mulss xmm2, [rcx + rax*4 + 8]
addss xmm2, [r8 + rax*4 + 8]
movss xmm6, [rdx + rax*4 + 24]
mulss xmm3, [rcx + rax*4 + 12]
addss xmm3, [r8 + rax*4 + 12]
movss xmm7, [rdx + rax*4 + 28]
mulss xmm4, [rcx + rax*4 + 16]
addss xmm4, [r8 + rax*4 + 16]
mulss xmm5, [rcx + rax*4 + 20]
addss xmm5, [r8 + rax*4 + 20]
mulss xmm6, [rcx + rax*4 + 24]
addss xmm6, [r8 + rax*4 + 24]
mulss xmm7, [rcx + rax*4 + 28]
addss xmm7, [r8 + rax*4 + 28]
movss [rsi + rax*4], xmm0
movss [rsi + rax*4 + 4], xmm1
movss [rsi + rax*4 + 8], xmm2
movss [rsi + rax*4 + 12], xmm3
movss [rsi + rax*4 + 16], xmm4
movss [rsi + rax*4 + 20], xmm5
movss [rsi + rax*4 + 24], xmm6
movss [rsi + rax*4 + 28], xmm7
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
.size triad_sp, .-triad_sp


