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
.global triad_mem_avx_fma
.type triad_mem_avx_fma, @function
triad_mem_avx_fma :
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
vmovaps ymm1, [rdx + rax*8]
vmovaps ymm2, [rcx + rax*8]
vmovaps ymm3, [rdx + rax*8+32]
vmovaps ymm4, [rcx + rax*8+32]
vfmadd213pd ymm1, ymm2, [r8 + rax*8]
vfmadd213pd ymm3, ymm4, [r8 + rax*8+32]
vmovntpd [rsi + rax*8], ymm1
vmovntpd [rsi + rax*8+32], ymm3
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
.size triad_mem_avx_fma, .-triad_mem_avx_fma


