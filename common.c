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

char* strconc(char *str1, const char *append)
{
	char *output = str1;

	for(; *str1; ++str1);
	while((*str1++ = *append++) != 0);
    return(output);
}