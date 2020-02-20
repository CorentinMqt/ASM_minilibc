BITS 64

SECTION .text
GLOBAL my_memmove

my_memmove:
    XOR rcx, rcx

loop:
    cmp rcx, rdx
    je end
    mov r8b, [rsi+rcx]
    mov [rdi+rcx],r8b
    inc rcx
    jmp loop

end:
    mov rax, rdi
    RET