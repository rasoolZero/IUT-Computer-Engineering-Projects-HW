section .text
  global _start
    _start:
	BITS 32
	jmp short two
    one:
 	pop ebx
 	xor eax, eax
 	mov [ebx+12], al
 	mov [ebx+13], ebx
 	mov [ebx+17], eax
 	lea ecx, [ebx+13]
 	push eax
 	push "a=11"
 	mov [ebx+21],esp
 	push eax
 	push "b=22"
 	mov [ebx+25],esp
 	mov [ebx+29], eax
 	lea edx, [ebx+21]
 	mov al,  0x0b
 	int 0x80
     two:
 	call one
 	db '/usr/bin/env*AAAABBBBCCCCDDDDEEEE'
                   ;12
                    ;13
                        ;17
                            ;21
                                ;25
                                    ;29
 	; AAAA will be pointer to /usr/bin/env
 	; BBBB will be null pointer
 	; CCCC will be pointer to a=11
 	; DDDD will be pointer to b=22
 	; EEEE will be null pointer
