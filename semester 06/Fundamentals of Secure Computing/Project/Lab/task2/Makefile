TARGET = mysh2
  
all: $(TARGET)

mysh2: mysh2.s
	nasm -f elf32 $@.s -o $@.o
	ld --omagic -m elf_i386 $@.o -o $@
clean:
	rm -f *.o *.out $(TARGET)

