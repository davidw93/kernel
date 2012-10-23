#include "common.h"

void outb(unsigned short port, unsigned char value)
{
	asm volatile("outb %1, %0" : : "dN" (port), "a" (value));
}

unsigned char inb(unsigned short port)
{
	unsigned char ret;
	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

unsigned short inw(unsigned short port)
{
	unsigned short ret;
	asm volatile("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

void memcopy(unsigned char *dest, const unsigned char *src, unsigned int len)
{
    const unsigned char *sp = (const unsigned char *)src;
    unsigned char *dp = (unsigned char *)dest;
    for(; len != 0; len--) *dp++ = *sp++;
}

void memoryset(unsigned char *dest, unsigned char val, unsigned int len)
{
    unsigned char *temp = (unsigned char *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

char* strconc(const char *str1, const char *append)
{
	unsigned char *str1_readable = (unsigned char *)str1;
	char *output = str1_readable;

	for(; *str1_readable; ++str1_readable);
	while((*str1_readable++ = *append++) != 0);
    return(output);
}