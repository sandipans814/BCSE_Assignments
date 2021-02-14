; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Print the system time and date.
;  Command : nasm -f elf32 13.asm && gcc -m32 13.o -o 13 && ./13
; ---------------------------------------------------------------------------------

section .data
    PrintNum    db "Seconds since UNIX epoch: %d", 10, 0        

section .text]
    extern printf       
    global main

main:
    push    ebp
    mov     ebp,esp
    push    ebx
    push    esi
    push    edi                 

    mov     eax, 13
    push    eax
    mov     ebx, esp
    int     0x80
    pop     eax

    push    eax        
    push    PrintNum
    call    printf 
    add     esp,8   

    pop     edi         
    pop     esi
    pop     ebx
    mov     esp,ebp
    pop     ebp
    ret

          


