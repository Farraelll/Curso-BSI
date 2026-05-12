section .data
    msg db 'Olá, ', 0

section .bss
    nome resb 100

section .text
    global _start

_start:
    ; Lê o nome do usuário
    mov eax, 3
    mov ebx, 0
    mov ecx, nome
    mov edx, 100
    int 0x80

    ; Imprime a saudação
    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, 6
    int 0x80

    ; Imprime o nome
    mov eax, 4
    mov ebx, 1
    mov ecx, nome
    mov edx, 100
    int 0x80

    ; Fim do programa
    mov eax, 1
    xor ebx, ebx
    int 0x80