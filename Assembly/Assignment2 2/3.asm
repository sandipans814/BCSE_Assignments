; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Program to print pairs of even numbers where the summation of the numbers in each pair is 100.
;  Command : nasm -felf 3.asm && ld -m elf_i386 3.o -o 3 && ./3
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text
      
_start:   
          mov       edx, 0
          mov       ecx, 100

_loop:
          mov       eax, edx
          add       eax, ecx
          sub       eax, 100
          cmp       eax, 0
          
          jne       change

          mov       eax, edx
          call      iprint
          mov       eax, delim
          call      sprint
          mov       eax, ecx
          call      iprintLF

change:
          add       edx, 2
          sub       ecx, 2
          
          cmp       edx, 102
          je        exit
          jmp       _loop

exit:
          call      quit

          section   .data
delim:    db        '-'