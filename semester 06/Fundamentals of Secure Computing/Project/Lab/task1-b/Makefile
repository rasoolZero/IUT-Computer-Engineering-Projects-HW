TARGET = mysh
  
all: $(TARGET)

mysh: mysh.s
	nasm -f elf32 $@.s -o $@.o
	ld -m elf_i386 $@.o -o $@
clean:
	rm -f *.o *.out $(TARGET)

