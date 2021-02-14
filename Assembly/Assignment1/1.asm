; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Display your name and program title on the output screen.
;  Command : nasm -felf 1.asm && ld -m elf_i386 1.o -o 1 && ./1
; ---------------------------------------------------------------------------------


global    _start

          section   .text

_start:   
          mov       ebx, message
          mov       eax, ebx

next_char:
          cmp       byte[eax], 0
          jz        finished
          inc       eax
          jmp       next_char

finished:
          sub       eax, ebx

          mov       edx, eax                               
          mov       ecx, message
          mov       ebx, 1
          mov       eax, 4             
          int       80h                     

          mov       ebx, 0                  
          mov       eax, 1                  
          int       80h                     

          section   .data
message:  db        "Name: Sandipan Saha", 0x0a, "Program: 1", 0x0a      
