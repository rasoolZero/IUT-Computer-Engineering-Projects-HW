section .text
  global _start
    _start:
      xor  eax, eax    
      ; For environment variable 
      push eax
      push "1234"
      push "aaa="
      mov ebx, esp ; ebx now points to aaa=1234
      push eax
      push "5678"
      push "bbb="
      mov ecx, esp ; ecx now points to bbb=5678
      mov edx, "4xxx"
      shl edx,24
      shr edx,24
      push edx
      push "=123"
      push "cccc"
      mov edx, esp ; edx now points to cccc=1234
      push eax
      push ebx
      push ecx
      push edx
      mov edx, esp ; edx now points to environment variables
      ; Store the argument string on stack
      push eax          ; Use 0 to terminate the string
      push "/env"
      push "/bin"
      push "/usr"
      mov  ebx, esp     ; Get the string address
      ; Construct the argument array argv[]
      push eax          ; argv[1] = 0
      push ebx          ; argv[0] = "/usr/bin/env"
      mov  ecx, esp     ; Get the address of argv[]
      ; Invoke execve()
      xor  eax, eax     ; eax = 0x00000000
      mov   al, 0x0b    ; eax = 0x0000000b
      int 0x80