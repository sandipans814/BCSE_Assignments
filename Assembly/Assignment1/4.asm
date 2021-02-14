; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Find the second max and second min from an array.
;  Command : nasm -felf 4.asm && ld -m elf_i386 4.o -o 4 && ./4
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
          mov       eax, [edx + 1*4]
          call      iprintLF
          
          mov       eax, msg_max
          call      sprint
          mov       ebx, len
          sub       ebx, 2
          mov       eax, [edx + ebx*4]
          call      iprintLF

          call      quit
          
          section   .data
space:    db        " ", 0
nums:     dd        2,8,6,9,4,3,1,2
len:      equ       ($ - nums)/4
msg1:     db        "ARRAY: ", 0
msg_max:  db        "SECOND MAXIMUM: ", 0
msg_min:  db        "SECOND MINIMUM: ", 0