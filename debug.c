#define DEBUG
#include "debug.h"
#include "kscreen.h"
#include "common.h"

void dbg_msg(char* msg)
{
#ifdef DEBUG
	char* output = strconc("[DEBUG] ", msg);
    k_print_str_p(output);
#endif
}