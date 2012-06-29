#include "common.h"
#include "isr.h"
#include "kscreen.h"
#include "debug.h"

void isr_handler(registers_t regs)
{
	dbg_isr_msg("ISR HANDLED AT: ", regs.int_no);
}