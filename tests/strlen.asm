BITS 64

SECTION .text
GLOBAL my_strlen

my_strlen:
    XOR rax, rax

loop:
    cmp BYTE [rdi],0
    je end
    inc rax
    inc rdi
    jmp loop

end:
    RET