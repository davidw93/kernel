TARGET=i586-elf
CC=$(TARGET)-gcc
LD=$(TARGET)-ld
CFLAGS=-Wall -nostdlib -nostartfiles -nodefaultlibs -c
LDFLAGS=-T linker.ld
SOURCES=boot.c common.c cpu.c debug.c descriptor_tables.c isr.c kernel.c kscreen.c timer.c
OBJECTS=$(SOURCES:.c=.o)
ASM_SOURCES=interrupts.s loader.s gdt.s
ASM_OBJECTS=$(ASM_SOURCES:.s=.o)

all: asm kernel bootimage

asm: $(ASM_OBJECTS)
	
.s.o:
	nasm -f elf $< -o $@
	
kernel: $(OBJECTS) 
	$(LD) $(LDFLAGS) -o kernel.bin loader.o interrupts.o gdt.o  $(OBJECTS) 

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	
bootimage:
	cat misc/stage1 misc/stage2 misc/pad kernel.bin > floppy.img

run-emu:
	qemu-system-i386 -monitor stdio -fda floppy.img -kernel kernel.bin

clean:
	rm $(OBJECTS) $(ASM_OBJECTS)
	rm kernel.bin
	rm floppy.img
