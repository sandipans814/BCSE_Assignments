; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Find maximum and minimum from an array.
;  Command : nasm -felf 8.asm && ld -m elf_i386 8.o -o 8 && ./8
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text


_start:           
          mov       edx, nums
          
          mov       eax, msg1
          call      sprint
          call      array_print

          call      sort

          mov       eax, msg_min
          call      sprint
          mov       eax, [edx]
          call      iprintLF
          
          mov       eax, msg_max
          call      sprint
          mov       ebx, len
          dec       ebx
          mov       eax, [edx + ebx*4]
          call      iprintLF

          call      quit
          
          section   .data
space:    db        " ", 0
nums:     dd        2,8,6,9,4,3,1,2
len:      equ       ($ - nums)/4
msg1:     db        "ARRAY: ", 0
msg_max:  db        "MAXIMUM: ", 0
msg_min:  db        "MINIMUM: ", 0