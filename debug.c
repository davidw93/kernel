#include "debug.h"
#include "kscreen.h"
#include "common.h"

void dbg_msg(char* msg)
{
	char *output = strconc("[DEBUG] ", msg);
	kscrn_setcolour(0x04);
	kscrn_write(output);
	format();
}
void dbg_isr_msg(char* msg, unsigned int reg)
{
	char* output = strconc("[DEBUG] ", msg);
	kscrn_setcolour(0x04);
    kscrn_write(output);
    kscrn_write_hex(reg);
    format();
}

void format()
{
	kscrn_newline();
    kscrn_defaultcol();
}