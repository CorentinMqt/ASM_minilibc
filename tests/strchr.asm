BITS 64

SECTION .text
GLOBAL my_strchr

my_strchr:
	xor rcx, rcx

loop:
	mov dl, BYTE [rdi+rcx]
	cmp dl, sil
	je found
	cmp dl, 0
	je end
	inc rcx
	jmp loop

found:
    mov rax, rdi
    add rax, rcx
    ret

end:
	mov rax, 0
	ret