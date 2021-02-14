; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Convert binary to decimal.
;  Command : nasm -felf 2a.asm && ld -m elf_i386 2a.o -o 2a && ./2a
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text
      
_start:   
          mov       eax, [num]
          call      iprintLF

          call      quit

          section   .data
num:      dq        0b100100

