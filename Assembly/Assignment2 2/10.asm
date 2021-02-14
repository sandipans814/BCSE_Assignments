; ---------------------------------------------------------------------------------  
;  Author  : Sandipan Saha
;  Program : Print prime numbers between 1 to 100.
;  Command : nasm -felf 10.asm && ld -m elf_i386 10.o -o 10 && ./10
; ---------------------------------------------------------------------------------

%include  'functions.asm'

global    _start

          section   .text

check_prime:
          push      edx
          push      ecx
          push      ebx

          mov       ecx, 0 
prime_loop:
          push      eax
          mov       edx, 0
          mov       ebx, [nums + ecx*4]
          idiv      ebx

          cmp       edx, 0
          pop       eax
          je        factor_found
          
          inc       ecx
          cmp       ecx, 4
          jb        prime_loop  

          mov       eax, 1
          jmp       quit_prime    
factor_found:
          mov       eax, 0
          jmp       quit_prime       
quit_prime:          
          pop       ebx
          pop       ecx
          pop       edx
          ret

_start:   
          mov       ecx, 0

_loop:          
          mov       eax, [nums + ecx*4]
          call      iprintLF
          inc       ecx
          cmp       ecx, 4
          jb        _loop
         
          mov       ecx, 11

all_primes_loop:
          mov       eax, ecx
          call      check_prime
          cmp       eax, 1          
          jne       inc_loop
          mov       eax, ecx
          call      iprintLF
inc_loop:  
          inc       ecx
          cmp       ecx, [limit]
          jb        all_primes_loop       
          call      quit    

          section   .data
nums:     dd        2,3,5,7
limit:    dq        100