%include        '../functions.asm'
 
SECTION .text
global  _start
 
_start:
 
    mov     ecx, 0          ; ecx is initalised to zero.
 
nextChar:
    inc     ecx             ; increment ecx
 
    mov     eax, ecx        ; move the address of our integer into eax
    add     eax, 64         ; add 48 to our number to convert from integer to ascii for printing
    push    eax             ; push eax to the stack
    mov     eax, esp        ; get the address of the character on the stack
    call    sprintLF        ; call our print function
 
    pop     eax             ; clean up the stack so we don't have unneeded bytes taking up space
    cmp     ecx, 26         ; have we reached 10 yet? compare our counter with decimal 10
    jne     nextChar      ; jump if not equal and keep counting
 
    call    quit