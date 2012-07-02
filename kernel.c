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
    k_clear_screen();
    kscrn_write("Hello, world!\n");
    asm volatile("sti");
    init_timer(50);
}