#include "common.h"
#include "isr.h"
#include "kscreen.h"
#include "debug.h"

isr_t interrupt_handlers[256];

const char *exception_messages[] =
{
	"Division By Zero",
	"Debug",
	"Non Maskable Interrupt",
	"Breakpoint",
	"Into Detected Overflow",
	"Out of Bounds",
	"Invalid Opcode",
	"No Coprocessor",
	"Double Fault",
	"Coprocessor Segment Overrun",
	"Bad TSS",
	"Segment Not Present",
	"Stack Fault",
	"General Protection Fault",
	"Page Fault",
	"Unknown Interrupt",
	"Coprocessor Fault",
	"Alignment Check",
	"Machine Check",
	"Reserved",
	"Reserved"
};

void isr_handler(registers_t regs)
{
	if(regs.int_no < 32)
	{
		char* output = strconc(exception_messages[regs.int_no], " Exception. System going down for Halt! \n");
		dbg_msg(output);
		/*
		** Just using an infinite loop to halt the system
		*/
		for(;;);
	}
}

void irq_handler(registers_t regs)
{
	if(regs.int_no >= 40)
	{
		//Send reset signal to slave PIC
		outb(0xA0, 0x20);
	}
	//Send reset to master PIC
	outb(0x20, 0x20);

	if(interrupt_handlers[regs.int_no] != 0)
	{
		isr_t handler = interrupt_handlers[regs.int_no];
		handler(regs);
	}
}

void register_interrupt_handler(unsigned char n, isr_t handler)
{
	interrupt_handlers[n] = handler;
}