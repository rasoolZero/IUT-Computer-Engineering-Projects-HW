section .text
  global _start
    _start:
      ; The following code calls execve("/bin/bash", ...)
      xor rax, rax
      mov al, 'h'
      mov rdx, '/bin/bas'
      push rax
      push rdx
      
      mov rdi, rsp        ; 1st argument
      xor  rdx, rdx       ; 3rd argument
      push rdx 
      push rdi
      mov rsi, rsp        ; 2nd argument
      xor  rax, rax
      mov al, 0x3b        ; execve()
      syscall