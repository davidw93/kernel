TARGET=i586-elf
CC=$(TARGET)-gcc
LD=$(TARGET)-ld
CFLAGS=-Wall -nostdlib -nostartfiles -nodefaultlibs -c
LDFLAGS=-T linker.ld
SOURCES=boot.c common.c cpu.c debug.c descriptor_tables.c isr.c kernel.c kscreen.c timer.c
OBJECTS=$(SOURCES:.c=.o)

all: asm $(OBJECTS) kernel bootimage

asm:
	nasm -f elf -o gdt.o gdt.s
	nasm -f elf -o interrupts.o interrupts.s
	nasm -f elf -o loader.o loader.s
	
kernel: $(OBJECTS) 
	$(LD) $(LDFLAGS) -o kernel.bin loader.o interrupts.o gdt.o  $(OBJECTS) 

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	
bootimage:
	cat misc/stage1 misc/stage2 misc/pad kernel.bin > floppy.img

run-emu:
	qemu-system-i386 -monitor stdio -fda floppy.img -kernel kernel.bin

gitclean:
	rm *.o
	rm kernel.bin
	rm floppy.img
	rm *~
