#include "debug.h"
#include "kscreen.h"
#include "common.h"

void dbg_msg(char* msg)
{
	char *output = strconc("[DEBUG] ", msg);
	kscrn_setcolour(0x04);
	kscrn_write(output);
	kscrn_newline();
	kscrn_defaultcol();
}
void dbg_isr_msg(char* msg, unsigned int reg)
{
	char* output = strconc("[DEBUG] ", msg);
	kscrn_setcolour(0x04);
    kscrn_write(output);
    kscrn_write_hex(reg);
    kscrn_newline();
    kscrn_defaultcol();
}