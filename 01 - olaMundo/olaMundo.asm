section .data
    msg db 'Olá mundo!', 0x0A

section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, 12
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall