#include "descriptor_tables.h"
#include "kernel.h"
#include "boot.h"
#include "cpu.h"
#include "kscreen.h"
#include "debug.h"

void kmain()
{
    extern unsigned long magic;
    extern void *mbd;
 
    if ( magic != 0x2BADB002 )
    {
        k_print_str("Error occurred while booting");
        return;
    }

    char * boot_loader_name =(char*) ((long*)mbd)[16];
 
    announce();
    if (irq_enabled() == 1) dbg_msg("IRQ enabled");
}

void announce() 
{
    init_descriptor_tables();
    k_clear_screen();
    k_print_str_p("David's basic 'kernel'");
    asm volatile("int $0x3");
}
