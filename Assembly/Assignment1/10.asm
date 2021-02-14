; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Print letters from A to Z
;  Command : nasm -felf 10.asm && ld -m elf_i386 10.o -o 10 && ./10
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text
_start:   
          mov       ecx, [count]
          mov       edx, char
        
_loop:    
          mov       eax, edx
          call      sprintLF

          mov       eax, [edx]
          inc       eax
          mov       [edx], eax

          dec       ecx          
          jnz       _loop

          call      quit

          section   .data
char:     db        'A'
count:    dq        26

