; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Program to perform binary search
;  Command : nasm -felf 9b.asm && ld -m elf_i386 9b.o -o 9b && ./9b
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text

_loop:
          cmp       ecx, ebx
          jb        not_found

          mov       eax, ebx
          add       eax, ecx

          push      edx
          mov       edx, 0
          mov       esi, 2
          idiv      esi
          pop       edx

          push      ebx
          mov       ebx, [target]
          cmp       ebx, [edx + eax*4]

          jb        search_low
          je        found          
          ja        search_high
found:
          pop       ebx
          mov       eax, 1
          ret
search_low:
          pop       ebx
          sub       eax, 1
          mov       ecx, eax
          jmp       _loop
search_high:
          pop       ebx
          add       eax, 1
          mov       ebx, eax
          jmp       _loop
not_found:
          mov       eax, 0
          ret

_start:           
          mov       edx, nums
          mov       ecx, len
          dec       ecx
          mov       ebx, 0

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
target:   dd        5
nfmsg:    db        "Absent", 0
fmsg:     db        "Present", 0