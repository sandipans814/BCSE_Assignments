; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Substring deletion from a given string.
;  Command : nasm -felf 7.asm && ld -m elf_i386 7.o -o 7 && ./7
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text

_loop:    mov       eax, edx
          add       eax, ecx    
          cmp       ecx, [end]
          ja        loop_print       
          cmp       ecx, [start]
          jb        loop_print
          jmp       loop_inc
loop_print:   
          call      charprint
loop_inc:  
          inc       ecx     
          dec       ebx
          jnz       _loop
          ret 

_start:           
          mov       edx, msg
          mov       ecx, 0
          mov       ebx, len
          
          call      _loop

          call      quit
          
          section   .data
msg:      db        "Hello World", 10
len:      equ       $ - msg
start:    dq        2
end:      dq        3  


