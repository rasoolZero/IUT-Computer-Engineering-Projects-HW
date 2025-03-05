TARGET = mysh_64
  
all: $(TARGET)

mysh_64: mysh_64.s
	nasm -f elf64 $@.s -o $@.o
	ld $@.o -o $@
clean:
	rm -f *.o *.out $(TARGET)

