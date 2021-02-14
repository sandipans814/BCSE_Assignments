; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Multiply two 32 bit numbers.
;  Command : nasm -felf 4.asm && ld -m elf_i386 4.o -o 4 && ./4
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text
_start:   
          mov       eax, msg
          call      sprint
        
          mov       ebx, [num2] 
          mov       eax, [num1]
          imul      ebx
          call      iprintLF

          call      quit
          
          section   .data
num1:     dq        0x00000255
num2:     dq        0x00000002
 msg:     db        "Multiplication Result: ", 0h

