; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : GCD and LCM of 3 numbers
;  Command : nasm -felf 8.asm && ld -m elf_i386 8.o -o 8 && ./8
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text

gcd:
          push      edx
          push      ecx
          push      ebx

          cmp       eax, ebx
          ja        after_swap

          mov       ecx, eax
          mov       eax, ebx
          mov       ebx, ecx           

after_swap:
          mov       edx, 0
          idiv      ebx
          mov       eax, edx

          cmp       eax, 0
          jne       rec_gcd

          mov       eax, ebx

          pop       ebx
          pop       ecx
          pop       edx
          ret

rec_gcd:
          mov       ecx, eax
          mov       eax, ebx
          mov       ebx, ecx

          call      gcd

          pop       ebx
          pop       ecx
          pop       edx
          ret

_start:   

          mov       eax, msg1
          call      sprint
          
          mov       ebx, [num1]
          mov       eax, [num2]
          call      gcd    
          mov       edi, eax  
          mov       ebx, [num3]
          call      gcd 
          call      iprintLF
          mov       esi, eax

          mov       eax, msg2
          call      sprint   
          mov       eax, [num1]
          mov       ebx, [num2]
          mov       ecx, [num3]
          imul      ebx
          imul      ecx
          mov       edx, 0
          idiv      edi
          idiv      esi

          call      iprintLF
          call      quit    

          section   .data
num1:     dq        100
num2:     dq        200
num3:     dq        300
msg1:     db        "GCD = ", 0
msg2:     db        "LCM = ", 0