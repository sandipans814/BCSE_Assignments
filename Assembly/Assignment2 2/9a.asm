; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Program to perform linear search
;  Command : nasm -felf 9a.asm && ld -m elf_i386 9a.o -o 9a && ./9a
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text

_loop:
          mov       eax, [edx+ecx*4]
          cmp       eax, [target]
          je        loop_found
          inc       ecx
          cmp       ecx, len
          je        loop_not_found
          jmp       _loop
loop_found:
          mov       eax, 1
          ret
loop_not_found:
          mov       eax, 0
          ret    

_start:           
          mov       edx, nums
          mov       ecx, 0

          call      _loop

          cmp       eax, 1
          jb        nf_prompt

f_prompt:
          mov       eax, fmsg
          call      sprintLF
          call      quit

nf_prompt:
          mov       eax, nfmsg
          call      sprintLF
          call      quit
          
          section   .data
nums:     dd        1,2,3,4,5,6,7,8,9,10
len:      equ       ($ - nums)/4
target:   dd        11
nfmsg:    db        "Absent", 0
fmsg:     db        "Present", 0


