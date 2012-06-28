#ifndef __CPU_H
#define __CPU_H

enum FLAG_SHIFT {
    INTERRUPT_FLAG = 9,
    XYZ
};

inline void cpuid(int code, unsigned int* a, unsigned int* d);
inline int cpuid_str(int code, unsigned int result[4]);

int irq_enabled();
int irq_init();
#endif
