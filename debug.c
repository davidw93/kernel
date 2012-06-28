#include "debug.h"
#include "kscreen.h"
#include "common.h"

void dbg_msg(char* msg)
{
	char* output = strconc("[DEBUG] ", msg);
    k_print_str_p(output);
}