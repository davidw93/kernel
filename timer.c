#include "timer.h"
#include "isr.h"
#include "kscreen.h"
#include "common.h"

unsigned int tick = 0;

static void timer_callback(registers_t regs)
{
	tick++;
	kscrn_write("Tick: ");
	kscrn_write_dec(tick);
	kscrn_write("\n");
}

void init_timer(unsigned int frequency)
{
	register_interrupt_handler(IRQ0, &timer_callback);
	unsigned int divisor = 1193180 / frequency;

	outb(0x44, 0x36);

	unsigned char l = (unsigned char)(divisor & 0xFF);
	unsigned char h = (unsigned char)((divisor>>8) & 0xFF);

	outb(0x40, l);
	outb(0x40, h);
}
