; ----------------------------------
;   void iprint(integer)
;   returns : void

iprint:
          push      eax
          push      ecx
          push      edx
          push      esi
          mov       ecx, 0

divide_loop:
          inc       ecx
          mov       edx, 0
          mov       esi, 10
          idiv      esi
          add       edx, 48
          push      edx
          cmp       eax, 0
          jnz       divide_loop

print_loop:
          dec       ecx
          mov       eax, esp
          call      sprint
          pop       eax
          cmp       ecx, 0
          jnz       print_loop

          pop       esi
          pop       edx
          pop       ecx
          pop       eax
          ret
; ----------------------------------

; ----------------------------------
;   void iprintLF(integer)
;   returns : void

iprintLF:
          call      iprint

          push      eax
          mov       eax, 0Ah
          push      eax
          mov       eax, esp
          
          call      sprint
          pop       eax
          pop       eax
          
          ret
; ----------------------------------

; ----------------------------------
;   int slen(string)
;   returns : message length -> int

slen:     push      ebx
          mov       ebx, eax

next_char:
          cmp       byte[eax], 0
          jz        finished
          inc       eax
          jmp       next_char 

finished:
          sub       eax, ebx
          pop       ebx
          ret
; ----------------------------------

; ----------------------------------
;   void sprint(string)
;   returns : void

sprint:
          push      edx
          push      ecx
          push      ebx
          push      eax

          call      slen
          
          mov       edx, eax
          pop       eax
        
          mov       ecx, eax
          mov       ebx, 1
          mov       eax, 4             
          int       80h        

          pop       ebx
          pop       ecx
          pop       edx             

          ret
; ----------------------------------

; ----------------------------------
;   void sprintLF(string)
;   returns : void

sprintLF:
          call      sprint

          push      eax
          mov       eax, 0Ah
          push      eax
          mov       eax, esp
          
          call      sprint
          pop       eax
          pop       eax
          
          ret
; ----------------------------------

; ----------------------------------
;   void exit()
;   returns : void

quit:
        mov         ebx, 0
        mov         eax, 1
        int         80h
        ret
; ----------------------------------


; ----------------------------------
;   void array_print(int* arr)
;   returns : void

array_print:
          push      eax
          push      ebx
          mov       ebx, 0
array_print_loop:
          mov       eax, [edx + ebx*4]
          call      iprint
          mov       eax, space
          call      sprint
          inc       ebx
          cmp       ebx, len
          jb        array_print_loop

          mov       eax, space
          call      sprintLF
          pop       ebx
          pop       eax
          ret
; ----------------------------------

; ----------------------------------
;   void swap(int* arr) (ascending)
;   returns : void

arr_swap:
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
sort_outer_loop:
          mov       edi, ecx
          mov       esi, ecx
          inc       esi
sort_inner_loop:
          mov       eax, [edx + esi*4]
          mov       ebx, [edx + edi*4]
          cmp       eax, ebx
          ja        sort_inner_loop_inc
          mov       edi, esi   
sort_inner_loop_inc:
          inc       esi           
          cmp       esi, len
          jb        sort_inner_loop

          mov       eax, ecx
          mov       ebx, edi
          call      arr_swap

          inc       ecx   
          mov       eax, len
          dec       eax        
          cmp       ecx, eax
          jb        sort_outer_loop      

          pop       edi
          pop       esi
          pop       ecx
          pop       ebx
          pop       eax

          ret
; ----------------------------------