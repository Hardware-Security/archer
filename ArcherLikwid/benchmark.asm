;section .text
%define nop8 db 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00

GLOBAL benchmark

benchmark:

push rbx
push rcx

lp:

;xbegin  FallBackError



db 0x90
;db 0x90
;db 0x90
;db 0x90
;db 0x90
;db 0x90
;db 0x90
;db 0x90





;xend
jmp    FunctionSuccessfullyExecuted 

FallBackError:

Nop

FunctionSuccessfullyExecuted :

Nop

loop lp

pop rcx
pop rbx

ret
ud2
