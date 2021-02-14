section .text
    global _start ; linker
_start:
    mov edx,len1 ; length
    mov ecx,name ; variable
    mov ebx,1 ;file descriptor
    mov eax,4 ; system call
    int 0x80

    mov edx,len2 ; length
    mov ecx,title ; variable
    mov ebx,1 ;file descriptor
    mov eax,4 ; system call
    int 0x80

    mov ebx,0
    mov eax,1
    int 0x80     
section .data
name db 'Sandipan Saha', 0Ah
len1 equ $ - name
title db 'Write and test a MASM program to Display your name and program title on the output screen.' , 0Ah 
len2 equ $ - title
