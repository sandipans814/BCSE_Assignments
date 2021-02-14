; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Display a terminating message.
;  Command : nasm -felf 5.asm && ld -m elf_i386 5.o -o 5 && ./5
; ---------------------------------------------------------------------------------

global    _start

          section   .text
_start:   
          mov       eax, 4                  ; system call for write
          mov       ebx, 1                  ; file handle 1 is stdout
          mov       ecx, message            ; address of string to output
          mov       edx, 13                 ; number of bytes
          int       80h                     ; invoke operating system to do the write

          mov       ebx, 0                  ; exit code 0
          mov       eax, 1                  ; system call for exit
          int       80h                     ; invoke operating system to exit

          section   .data
message:  db        "Hello World!", 10      ; note the newline at the end
