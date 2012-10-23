#include "cpu.h"

inline void cpuid(int code, unsigned int* a, unsigned int* d)
{
    asm volatile ("cpuid" : "=a"(*a), "=d"(*d) : "0"(code) : "ebx", "ecx");
}

inline int cpuid_str(int code, unsigned int result[4])
{
    asm volatile("cpuid" : "=a"(*result), "=b"(*(result+1)), "=c"(*(result+2)), "=d"(*(result+3)) : "a"(code));
    return (int)result[0];
}

inline int irq_enabled()
{
    int x;
    asm volatile("pushf; popl %0" : "=g"(x));
    return x & (1 << 9);
}
/*
int irq_init()
{

}
*/
