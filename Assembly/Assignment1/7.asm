; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Validate second number is less than the first.
;  Command : nasm -felf 7.asm && ld -m elf_i386 7.o -o 7 && ./7
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text
_start:   
          mov       ecx, [num1]
          mov       eax, [num2]
          
          sub       eax, ecx
          cmp       eax, 0

          jl        _less  

          mov       eax, [num1]
          call      iprint
          mov       eax, msg
          call      sprint       
          mov       eax, [num2]
          call      iprintLF

          call      quit

_less:
          mov       eax, [num2]
          call      iprint
          mov       eax, msg
          call      sprint       
          mov       eax, [num1]
          call      iprintLF    
        
          call      quit

          section   .data
num1:     dq        0x39
num2:     dq        0x40
 msg:     db        " is less than ", 0h

