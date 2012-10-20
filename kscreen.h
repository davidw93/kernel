#ifndef __KSCREEN_H
#define __KSCREEN_H

void kscrn_setcolour(unsigned char col);
void kscrn_defaultcol();
void kscrn_clear();
void kscrn_write(char *c);
void kscrn_write_hex(unsigned int n);
void kscrn_write_dec(unsigned int n);
void kscrn_newline();
#endif