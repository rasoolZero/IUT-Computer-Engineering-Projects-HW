section .text
  global _start
    _start:
      ; Store the argument string on stack
      xor  eax, eax 
      push eax          ; Use 0 to terminate the string
      push "//sh"
      push "/bin"
      mov  ebx, esp     ; Get the string address
      ; Construct the argument array argv[]
      
      mov edx, "-c**"
      shl edx, 16
      shr edx, 16
      push edx
      mov edx, esp      ; argv[1]
      
      mov ecx, "la**"
      shl ecx, 16
      shr ecx, 16
      push ecx
      push "ls -"
      mov ecx, esp      ; argv[2]
      
      push eax          ; argv[3] = 0
      push ecx          ; argv[2] points "ls -la"
      push edx          ; argv[1] points "-c"
      push ebx          ; argv[0] points "/bin//sh"
      mov  ecx, esp     ; Get the address of argv[]
   
      ; For environment variable 
      xor  edx, edx     ; No env variables 

      ; Invoke execve()
      xor  eax, eax     ; eax = 0x00000000
      mov   al, 0x0b    ; eax = 0x0000000b
      int 0x80
