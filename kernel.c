#include "descriptor_tables.h"
#include "kernel.h"
#include "boot.h"
#include "cpu.h"
#include "kscreen.h"
#include "debug.h"
#include "timer.h"

void kmain()
{
    init_descriptor_tables();
    announce();
}

void announce()
{
    kscrn_clear();
    kscrn_write("Hello, world!\n");
    
    kscrn_write("End of kernel: ");
    kscrn_write_hex((unsigned int) &kernel_end);
    
    asm volatile("sti");
    init_timer(50);
}
