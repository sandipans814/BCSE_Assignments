; ----------------------------------
;   void iprint(integer)
;   returns : void

iprint:
          push      eax
          push      ecx
          push      edx
          push      esi
          mov       ecx, 0

idivide_loop:
          inc       ecx
          mov       edx, 0
          mov       esi, 10
          idiv      esi
          add       edx, 48
          push      edx
          cmp       eax, 0
          jnz       idivide_loop

iprint_loop:
          dec       ecx
          mov       eax, esp
          call      sprint
          pop       eax
          cmp       ecx, 0
          jnz       iprint_loop

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
;   void charprint(char)
;   returns : void

charprint:
          push      edx
          push      ecx
          push      ebx
          push      eax

          mov       edx, 1
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