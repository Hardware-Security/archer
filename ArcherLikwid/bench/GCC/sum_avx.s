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
.global sum_avx
.type sum_avx, @function
sum_avx :
push rbp
mov rbp, rsp
push rbx
push r12
push r13
push r14
push r15
vxorpd ymm1, ymm1, ymm1
vmovapd ymm2, ymm1
vmovapd ymm3, ymm1
vmovapd ymm4, ymm1
vmovapd ymm5, ymm1
vmovapd ymm6, ymm1
vmovapd ymm7, ymm1
vmovapd ymm8, ymm1
xor   rax, rax
.align 16
1:
vaddpd ymm1, ymm1, [rsi + rax * 8]
vaddpd ymm2, ymm2, [rsi + rax * 8 + 32]
vaddpd ymm3, ymm3, [rsi + rax * 8 + 64]
vaddpd ymm4, ymm4, [rsi + rax * 8 + 96]
vaddpd ymm5, ymm5, [rsi + rax * 8 + 128]
vaddpd ymm6, ymm6, [rsi + rax * 8 + 160]
vaddpd ymm7, ymm7, [rsi + rax * 8 + 192]
vaddpd ymm8, ymm8, [rsi + rax * 8 + 224]
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
.size sum_avx, .-sum_avx


