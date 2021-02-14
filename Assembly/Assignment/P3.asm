%include        '../functions.asm'
 
SECTION .text
global  _start
 
_start:
 
    mov     eax, 0x4A6     ; move our first number into eax
    mov     ebx, 0x1B3      ; move our second number into ebx
    add     eax, ebx    ; add ebx to eax
    call    iprintLF    ; call our integer print with linefeed function
 
    call    quit