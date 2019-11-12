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
.global daxpy_mem_sse_fma
.type daxpy_mem_sse_fma, @function
daxpy_mem_sse_fma :
push rbp
mov rbp, rsp
push rbx
push r12
push r13
push r14
push r15
movaps xmm6, [rip+SCALAR]
xor   rax, rax
.align 16
1:
movaps xmm0, [rsi + rax*8]
movaps xmm1, [rsi + rax*8+16]
movaps xmm2, [rsi + rax*8+32]
movaps xmm3, [rsi + rax*8+48]
vfmadd213pd xmm0, xmm6, [rdx + rax*8]
vfmadd213pd xmm1, xmm6, [rdx + rax*8+16]
vfmadd213pd xmm2, xmm6, [rdx + rax*8+32]
vfmadd213pd xmm3, xmm6, [rdx + rax*8+48]
movntps [rdx + rax*8], xmm0
movntps [rdx + rax*8+16], xmm1
movntps [rdx + rax*8+32], xmm2
movntps [rdx + rax*8+48], xmm3
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
.size daxpy_mem_sse_fma, .-daxpy_mem_sse_fma


