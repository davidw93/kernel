#ifndef __KERNEL_H
#define __KERNEL_H

// &kernel_end is the address of the end of the kernel in memory
extern unsigned int kernel_end;

void kmain();
void announce();

#endif
