build: kernel.bin
	rm boot.o kernel.o

kernel.bin: boot.o kernel.o
	ld -m elf_i386 -o $@ -Tlinker.ld $^

boot.o:
	nasm boot.asm -f elf -o boot.o

kernel.o:
	gcc -g -m32 -std=gnu99 -ffreestanding -nostdlib -fno-builtin -fno-stack-protector -no-pie -fno-pic -Wall -Wextra -c kernel.c -o kernel.o

run: kernel.bin
	qemu-system-i386 -kernel kernel.bin