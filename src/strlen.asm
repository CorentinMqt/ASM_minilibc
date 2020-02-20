BITS 64

SECTION .text
GLOBAL strlen

strlen:
    XOR rax, rax

loop:
    cmp BYTE [rdi],0
    je end
    inc rax
    inc rdi
    jmp loop

end:
    RET