#include "descriptor_tables.h"
#include "kernel.h"
#include "boot.h"
#include "cpu.h"
#include "kscreen.h"
#include "debug.h"

void kmain()
{
    init_descriptor_tables();
    
    announce();

}

void announce()
{
    k_clear_screen();
    kscrn_write("Hello, world!\n");
    asm volatile("int $0x00");
    kscrn_write("Test");
    asm volatile("int $0x03");
}