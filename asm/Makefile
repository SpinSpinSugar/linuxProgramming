all: v1
v1:
	nasm -f elf64 lab4.asm -o lab4.o
	ld lab4.o -o lab4.out
v2:
	nasm -f elf64 lab4ig.asm -o lab4.o
	ld lab4.o -o lab4.out
clear:
	rm lab4.o lab4.out file.txt 
objdump:
	objdump -d lab4.o

