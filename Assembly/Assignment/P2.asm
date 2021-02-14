; ---------------------------------------------------------------------------------  
;  Author  : Pritthijit Nath
;  Program : Convert a letter from uppercase to lowercase.
;  Command : nasm -felf 2.asm && ld -m elf_i386 2.o -o 2 && ./2
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text

_start:   
          mov       eax, char
          add       byte[eax], 32
          call      sprintLF

          call      quit

          section   .data
char:     db        'B'

