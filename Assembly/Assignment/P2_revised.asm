section .data                           ;Data segment
   userMsg db 'Please enter a charecter: ' ;Ask the user to enter a number
   lenUserMsg equ $-userMsg             ;The length of the message
   dispMsg db 'Lower case of your entered alphabet is : '
   lenDispMsg equ $-dispMsg       
   newLineMsg db 0xA, 0xD
   newLineLen equ $-newLineMsg         

section .bss           ;Uninitialized data
   num resb 1
	
section .text          ;Code Segment
   global _start
	
_start:                ;User prompt
   mov eax, 4
   mov ebx, 1
   mov ecx, userMsg
   mov edx, lenUserMsg
   int 80h

   ;Read and store the user input
   mov eax, 3
   mov ebx, 2
   mov ecx, num  
   mov edx, 1          ;1Byte 
   int 80h
	
    ;main compute section
    mov eax,ecx
    add byte[eax],32
    mov ecx,eax
    int 80h

    ;Output the message 'The entered number is: '
   mov eax, 4
   mov ebx, 1
   mov ecx, dispMsg
   mov edx, lenDispMsg
   int 80h 

   ;Output the number entered
   mov eax, 4
   mov ebx, 1
   mov ecx, num
   mov edx, 1
   int 80h 

   mov eax, 4
   mov ebx, 1
   mov ecx, newLineMsg
   mov edx, newLineLen
   int 80h  
    
   ; Exit code
   mov eax, 1
   mov ebx, 0
   int 80h 
