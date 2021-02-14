; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Rename a file.
;  Command : nasm -felf 12.asm && ld -m elf_i386 12.o -o 12 && ./12
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text

_start:   
          
          mov       eax, 38
          mov       ebx, name_i
          mov       ecx, name_f
          int       80h
          
          mov       eax, prompt
          call      sprintLF


          call      quit    

          section   .data
name_i:   db        "hell_world.txt", 0
name_f:   db        "hello_world.txt", 0
prompt:   db        "File renamed."