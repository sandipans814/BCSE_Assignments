; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Add and subtract two 16 bit numbers.
;  Command : nasm -felf 1.asm && ld -m elf_i386 1.o -o 1 && ./1
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text
_start:   
          mov       eax, msg1
          call      sprint
        
          mov       ebx, [num2] 
          mov       eax, [num1]
          add       eax, ebx
          call      iprintLF

          mov       eax, msg2
          call      sprint

          mov       eax, [num1]
          sub       eax, ebx
          call      iprintLF

          call      quit
          
          section   .data
num1:     dq        0x0045
num2:     dq        0x0042
msg1:     db        "Addition Result: ", 0h
msg2:     db        "Subtraction Result: ", 0h

