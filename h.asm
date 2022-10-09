section .data
msg db 'hello world', 0xA
len equ $ - msg

section .text
    global _start
    _start:
        mov edx, len
        mov ecx, msg
        mov ebx, 1
        mob eax, 4
        int 0x80

        mov ebx, 0
        mov eax, 1
        int 0x80