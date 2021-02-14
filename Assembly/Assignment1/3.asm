; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Add two hexadecimal numbers.
;  Command : nasm -felf 3.asm && ld -m elf_i386 3.o -o 3 && ./3
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text

_start:   
          mov       eax, [num1]
          mov       ebx, [num2]
          add       eax, ebx
          call      iprintLF

          call      quit

          section   .data
num1:     dq        0x50
num2:     dq        0x40

