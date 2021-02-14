; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Divide a 16 bit number by a 8 bit number.
;  Command : nasm -felf 5.asm && ld -m elf_i386 5.o -o 5 && ./5
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text
_start:   
          mov       eax, msg1
          call      sprint
        
          mov       ebx, [num2] 
          mov       eax, [num1]
          idiv      ebx

          call      iprintLF

          mov       eax, msg2
          call      sprint

          mov       eax, edx
          call      iprintLF           

          call      quit
          
          section   .data
num1:     dq        0x04
num2:     dq        0x02
msg1:     db        "Division Quotient: ", 0h
msg2:     db        "Division Remainder: ", 0h

