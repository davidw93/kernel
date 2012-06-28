#ifndef __COMMON_H
#define __COMMON_H

void outb(unsigned short port, unsigned char value);
unsigned char inb(unsigned short port);
unsigned short inw(unsigned short port);
void memcopy(unsigned char *dest, const unsigned char *src, unsigned int len);
void memoryset(unsigned char *dest, unsigned char val, unsigned int len);
char* strconc(char *str1, const char *str2);

#endif