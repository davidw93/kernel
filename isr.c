#include "common.h"
#include "isr.h"
#include "kscreen.h"
#include "debug.h"

unsigned char *exception_messages[] =
{
	"Division By Zero",
	"Debug",
	"Non Maskable Interrupt",
	"Breakpoint",
	"Detected Overflow",
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