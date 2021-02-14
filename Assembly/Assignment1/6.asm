; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Take a character from the keyboard and print it.
;  Command : nasm -felf 6.asm && ld -m elf_i386 6.o -o 6 && ./6
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text
_start:   
          mov       eax, prompt
          call      sprint

          mov       edx, 255
          mov       ecx, sinput
          mov       ebx, 0
          mov       eax, 3
          int       80h

          mov       eax, result
          call      sprint
          
          mov       eax, sinput
          call      sprint

          call      quit

          section   .data
prompt:   db        "Enter a character: ", 0h
result:   db        "Entered: ", 0h

          section   .bss
sinput:   resb       255

