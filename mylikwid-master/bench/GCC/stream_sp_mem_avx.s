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
.global stream_sp_mem_avx
.type stream_sp_mem_avx, @function
stream_sp_mem_avx :
push rbp
mov rbp, rsp
push rbx
push r12
push r13
push r14
push r15
vmovaps ymm1, [rip+SCALAR]
xor   rax, rax
.align 16
1:
vmovaps ymm2, [rdx + rax*4]
vmovaps ymm3, [rdx + rax*4+32]
vmovaps ymm4, [rdx + rax*4+64]
vmovaps ymm5, [rdx + rax*4+96]
vmulps ymm2, ymm2, ymm1
vaddps ymm2, ymm2, [rcx + rax*4]
vmulps ymm3, ymm3, ymm1
vaddps ymm3, ymm3, [rcx + rax*4+32]
vmulps ymm4, ymm4, ymm1
vaddps ymm4, ymm4, [rcx + rax*4+64]
vmulps ymm5, ymm5, ymm1
vaddps ymm5, ymm5, [rcx + rax*4+96]
vmovntps [rsi + rax*4], ymm2
vmovntps [rsi + rax*4+32], ymm3
vmovntps [rsi + rax*4+64], ymm4
vmovntps [rsi + rax*4+96], ymm5
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
.size stream_sp_mem_avx, .-stream_sp_mem_avx


