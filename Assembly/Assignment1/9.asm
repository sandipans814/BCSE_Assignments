; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Loop until the user decides to quit
;  Command : nasm -felf 9.asm && ld -m elf_i386 9.o -o 9 && ./9
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text
_start:   
          mov       eax, prompt
          call      sprint
_loop:
         

          mov       edx, 1
          mov       ecx, sinput
          mov       ebx, 0
          mov       eax, 3
          int       80h

        
          mov       eax, [sinput]
          mov       ebx, [char]

          cmp       eax, ebx
          jne       _loop
        
          call      quit

          section   .data
char:     dq        'X'
prompt:   db        "Enter X to terminate: ", 0h

          section   .bss
sinput:   resb       1

