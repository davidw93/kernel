#define CHARS_PER_LINE 80

#include "kscreen.h"
#include "common.h"


unsigned short *video_memory = (unsigned short *)0xB8000;
unsigned char TEXT_COLOUR = 0x07;
unsigned char cursor_x = 0;
unsigned char cursor_y = 0;

void kscrn_setcolour(unsigned char col)
{
    TEXT_COLOUR = col;
}

void kscrn_defaultcol()
{
    TEXT_COLOUR = 0x07;
}

void move_cursor()
{
    unsigned short cursorLocation = cursor_y * 80 + cursor_x;
    outb(0x3D4, 14);                  // we are setting the high cursor byte.
    outb(0x3D5, cursorLocation >> 8); // Send the high cursor byte.
    outb(0x3D4, 15);                  // we are setting the low cursor byte.
    outb(0x3D5, cursorLocation);      // Send the low cursor byte.
}

void scroll()
{

    unsigned short blank = 0x20 | (TEXT_COLOUR << 8);

    if(cursor_y >= 25)
    {
        int i;

        for (i = 0*80; i < 24*80; i++)
        {
            video_memory[i] = video_memory[i+80];
        }

        for (i = 24*80; i < 25*80; i++)
        {
            video_memory[i] = blank;
        }

        cursor_y = 24;
    }
}


void kscrn_put(char c)
{
    unsigned char backColour = 0;
    unsigned char foreColour = 15;

    unsigned short attribute = TEXT_COLOUR << 8;
    unsigned short *location;

    if (c == 0x08 && cursor_x)
    {
        cursor_x--;
    }

    else if (c == 0x09)
    {
        cursor_x = (cursor_x+8) & ~(8-1);
    }

    else if (c == '\r')
    {
        cursor_x = 0;
    }

    else if (c == '\n')
    {
        cursor_x = 0;
        cursor_y++;
    }

    else if(c >= ' ')
    {
        location = video_memory + (cursor_y*80 + cursor_x);
        *location = c | attribute;
        cursor_x++;
    }

    if (cursor_x >= 80)
    {
        cursor_x = 0;
        cursor_y ++;
    }

    scroll();
    move_cursor();

}

void kscrn_clear()
{
    unsigned short blank = 0x20 | (TEXT_COLOUR << 8);

    int i;
    for (i = 0; i < 80*25; i++)
    {
        video_memory[i] = blank;
    }

    cursor_x = 0;
    cursor_y = 0;
    move_cursor();
}

void kscrn_write(const char *c)
{
    int i = 0;
    while (c[i])
    {
        kscrn_put(c[i++]);
    }
}

void kscrn_write_hex(unsigned int n)
{
    int tmp;

    kscrn_write("0x");

    char noZeroes = 1;

    int i;
    for (i = 28; i > 0; i -= 4)
    {
        tmp = (n >> i) & 0xF;
        if (tmp == 0 && noZeroes != 0)
        {
            continue;
        }
    
        if (tmp >= 0xA)
        {
            noZeroes = 0;
            kscrn_put (tmp-0xA+'a' );
        }
        else
        {
            noZeroes = 0;
            kscrn_put( tmp+'0' );
        }
    }
  
    tmp = n & 0xF;
    if (tmp >= 0xA)
    {
        kscrn_put (tmp-0xA+'a');
    }
    else
    {
        kscrn_put (tmp+'0');
    }

}

void kscrn_write_dec(unsigned int n)
{

    if (n == 0)
    {
        kscrn_put('0');
        return;
    }

    int acc = n;
    char c[32];
    int i = 0;
    while (acc > 0)
    {
        c[i] = '0' + acc%10;
        acc /= 10;
        i++;
    }
    c[i] = 0;

    char c2[32];
    c2[i--] = 0;
    int j = 0;
    while(i >= 0)
    {
        c2[i--] = c[j++];
    }
    kscrn_write(c2);

}

void kscrn_newline()
{
    int i = 0;
    char *newline = "\n";
    while(newline[i])
    {
        kscrn_put(newline[i++]);
    }
}