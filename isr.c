#include "common.h"
#include "isr.h"
#include "kscreen.h"

void isr_handler(registers_t regs)
{
	k_print_str_p("recieved interrupt");
}