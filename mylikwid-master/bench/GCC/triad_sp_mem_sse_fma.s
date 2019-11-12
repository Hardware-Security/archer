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
.global triad_sp_mem_sse_fma
.type triad_sp_mem_sse_fma, @function
triad_sp_mem_sse_fma :
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
movaps xmm0, [rdx + rax*4]
movaps xmm1, [rdx + rax*4+16]
movaps xmm2, [rdx + rax*4+32]
movaps xmm3, [rdx + rax*4+48]
movaps xmm4, [rcx + rax*4]
movaps xmm5, [rcx + rax*4+16]
movaps xmm6, [rcx + rax*4+32]
movaps xmm7, [rcx + rax*4+48]
vfmadd213ps xmm0, xmm4, [r8 + rax*4]
vfmadd213ps xmm1, xmm5, [r8 + rax*4+16]
vfmadd213ps xmm2, xmm6, [r8 + rax*4+32]
vfmadd213ps xmm3, xmm7, [r8 + rax*4+48]
movntps [rsi + rax*4], xmm0
movntps [rsi + rax*4+16], xmm1
movntps [rsi + rax*4+32], xmm2
movntps [rsi + rax*4+48], xmm3
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
.size triad_sp_mem_sse_fma, .-triad_sp_mem_sse_fma


