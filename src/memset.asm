BITS 64

SECTION .text
GLOBAL memset

memset:
    XOR rcx, rcx

loop:
    cmp rcx, rdx
    je end
    mov BYTE [rdi+rcx], sil
    inc rcx
    jmp loop

end:
    mov rax, rdi
    RET