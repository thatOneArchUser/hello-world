build: kernel.bin
	rm boot.o kernel.o

kernel.bin:
	nasm boot.asm -f elf -o boot.o
	gcc -g -m32 -std=gnu99 -ffreestanding -nostdlib -fno-builtin -fno-stack-protector -no-pie -fno-pic -Wall -Wextra -c kernel.c -o kernel.o
	ld -m elf_i386 -o kernel.bin -Tlinker.ld boot.o kernel.o

run: kernel.bin
	qemu-system-i386 -kernel kernel.bin
