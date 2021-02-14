; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Print Fibonacci series up to 10 terms.
;  Command : nasm -felf 6.asm && ld -m elf_i386 6.o -o 6 && ./6
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text

_loop:      
          mov       edx, eax
          add       eax, ebx
          call      iprintLF
          mov       ebx, edx
          dec       ecx
          jnz       _loop
          ret

_start:           
          mov       eax, 0
          call      iprintLF

          mov       eax, 1
          call      iprintLF

          mov       ebx, 0
          mov       eax, 1
          mov       ecx, [num]
          sub       ecx, 2
          
          call      _loop

          call      quit
          
          section   .data
num:      dq        10

