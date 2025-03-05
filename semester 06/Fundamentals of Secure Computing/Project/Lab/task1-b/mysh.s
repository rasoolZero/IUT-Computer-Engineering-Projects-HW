section .text
  global _start
    _start:
      mov eax, "hxxx"
      shl eax, 24
      shr eax, 24
      push eax
      push "/bas"
      push "/bin"
      mov  ebx, esp     

      ; Construct the argument array argv[]
      xor eax, eax
      push eax          ; argv[1] = 0
      push ebx          ; argv[0] points "/bin/bash"
      mov  ecx, esp     ; Get the address of argv[]
   
      ; For environment variable 
      xor  edx, edx     ; No env variables 

      ; Invoke execve()
      xor  eax, eax     ; eax = 0x00000000
      mov   al, 0x0b    ; eax = 0x0000000b
      int 0x80
