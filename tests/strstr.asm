BITS 64

SECTION .text
GLOBAL my_strstr

my_strstr:
    XOR rcx, rcx
    cmp BYTE [rsi],0
    jz notfound

loop:
    cmp BYTE [rsi+rcx],0
    jz found
    cmp BYTE [rdi],0
    jz notfound
    mov r11b, [rsi+rcx]
    cmp r11b, [rdi]
    jz skip
    cmp rcx, 0
    jz skip2

found:
    cmp rcx, 0
    jz end

skip:
    mov al, [rdi]
    mov al, [rsi]
    xor rcx, rcx

skip2:
    xor rcx, rcx

end:
    mov rcx, rdi
    ret

notfound:
    mov rax, 0
    ret