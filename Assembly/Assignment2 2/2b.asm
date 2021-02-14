; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Convert decimal to binary.
;  Command : nasm -felf 2b.asm && ld -m elf_i386 2b.o -o 2b && ./2b
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text
_start:   
          mov       eax, [num]
          mov       ecx, 0
          
bdivide_loop:
          inc       ecx
          mov       edx, 0
          mov       esi, 2
          idiv      esi
          add       edx, 48
          push      edx
          cmp       eax, 0
          jnz       bdivide_loop

bprint_loop:
          dec       ecx
          mov       eax, esp
          call      sprint
          pop       eax
          cmp       ecx, 0
          jnz       bprint_loop
          
bprintLF:       
          push      eax
          mov       eax, 0Ah
          push      eax
          mov       eax, esp
          call      sprint

          call      quit

          section   .data
num:      dq        45

