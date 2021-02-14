; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Selection sort.
;  Command : nasm -felf 11a.asm && ld -m elf_i386 11a.o -o 11a && ./11a
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text


array_print:
          push      eax
          push      ebx
          mov       ebx, 0
print_loop:
          mov       eax, [edx + ebx*4]
          call      iprint
          mov       eax, space
          call      sprint
          inc       ebx
          cmp       ebx, len
          jb        print_loop

          mov       eax, space
          call      sprintLF
          pop       ebx
          pop       eax
          ret


swap:
          push      ecx
          push      esi

          mov       ecx, [edx + ebx*4]
          mov       esi, [edx + eax*4]
          mov       [edx + ebx*4], esi
          mov       [edx + eax*4], ecx

          pop       esi
          pop       ecx      
          ret   

sort:
          push      eax
          push      ebx
          push      ecx
          push      esi
          push      edi
          
          mov       ecx, 0 
outer_loop:
          mov       edi, ecx
          mov       esi, ecx
          inc       esi
inner_loop:
          mov       eax, [edx + esi*4]
          mov       ebx, [edx + edi*4]
          cmp       eax, ebx
          ja        inner_loop_inc
          mov       edi, esi   
inner_loop_inc:
          inc       esi           
          cmp       esi, len
          jb        inner_loop

          mov       eax, ecx
          mov       ebx, edi
          call      swap

          inc       ecx   
          mov       eax, len
          dec       eax        
          cmp       ecx, eax
          jb        outer_loop      

          pop       edi
          pop       esi
          pop       ecx
          pop       ebx
          pop       eax

          ret

_start:           
          mov       edx, nums
          
          mov       eax, msg1
          call      sprint
          call      array_print

          call      sort

          mov       eax, msg2
          call      sprint
          call      array_print

          call      quit
          
          section   .data
space:    db        " ", 0
nums:     dd        2,8,6,9,4,3,1,2
len:      equ       ($ - nums)/4
msg1:     db        "INITIAL: ", 0
msg2:     db        "FINAL: ", 0
