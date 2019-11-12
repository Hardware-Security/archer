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
.global stream_mem_sse_fma
.type stream_mem_sse_fma, @function
stream_mem_sse_fma :
push rbp
mov rbp, rsp
push rbx
push r12
push r13
push r14
push r15
movaps xmm4, [rip+SCALAR]
xor   rax, rax
.align 16
1:
movapd xmm0, [rcx + rax*8]
vfmadd213pd xmm0, xmm4, [rdx + rax*8]
movntpd [rsi + rax*8], xmm0
add rax, 2
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
.size stream_mem_sse_fma, .-stream_mem_sse_fma


