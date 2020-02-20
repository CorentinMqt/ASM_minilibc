BITS 64

SECTION .text
GLOBAL strcmp

strcmp:
    XOR rax, rax

loop:
    cmp BYTE [rdi],0
    cmp BYTE [rsi],0
    je end
    mov dl, BYTE [rdi]
    mov cl, BYTE [rsi]
    cmp dl, 0
    je end
    cmp cl, 0
    je end
    cmp dl, cl
    jne end
    inc rdi
    inc rsi
    jmp loop

end:
    mov rax, [rdi]
    sub rax, [rsi]
    RET
