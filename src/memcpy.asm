BITS 64

SECTION .text
GLOBAL memcpy

memcpy:
    XOR rcx, rcx

loop:
	cmp rdx, rcx
	je end
 	mov r8b, [rsi+rcx]
 	mov [rdi+rcx], r8b
	inc rcx
	jmp loop

end:
	mov rax, rdi
	RET