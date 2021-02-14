SECTION .text
global  _start


_start:
	nop
	mov eax,0
	mov ebx,0
	
        mov ax,[a]
        mov bx,[c]
        cmp ax,bx
        jg validate
        jmp done

validate:
        mov edx,msglen
        mov ecx,msg
        mov ebx,1
        mov eax,4
        int 0x80
        jmp done
done:
	mov ebx, 0
	mov eax, 1
	int 0x80


        
section .data
a: dq 6
c: dq 10
msg db 'Validated Second Number is smaller', 0Ah
msglen equ $ - msg
msg2 db 'Not validated' , 0Ah
msglen2 equ $ - msg2

