#include "common.h"
#include "isr.h"
#include "kscreen.h"
#include "debug.h"

void isr_handler(registers_t regs)
{
	//Note that this isn't handle dec or HEX values yet
	dbg_msg(strconc("ISR HANDLED AT: ", regs.int_no));
}