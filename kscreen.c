#define TEXT_COLOUR 0x07
#define CHARS_PER_LINE 80

#include "kscreen.h"
#include "common.h"

int row = 0;
int col = 0;

void k_clear_screen()
{
	unsigned char* vram = (char*)0xB8000;
	int pos = 0;

	while(pos<80*25*2)
	{
		vram[pos++] = ' ';
		vram[pos++] = 0x07;
	}
	row=0;
	col=0;
}

void k_print_str(char* msg)
{
	unsigned char* vram = (char*)0xB8000;

	while(*msg != '\0')
	{
		*vram++ = *msg++;
		*vram++ = TEXT_COLOUR;
	}
	col++;
}

int k_print_str_p(char* msg)
{
    if (row > 80 || col > 25) return -1;

    int x = row;
    int y = col*2;
    int charcount = 0;
    
    unsigned char *vram = (char *)0xB8000 + x;

    while (*msg != '\0')
    {   
        int y_pos = CHARS_PER_LINE * y;
        vram[(x++)+y_pos] = *msg++;
        vram[x+y_pos] = TEXT_COLOUR;
        x++;
        charcount++;
        if(y > 2)
        {
        	int cursy = CHARS_PER_LINE * (y-(y/2)+1);
        	move_cursor(cursy, charcount);
        }
        else
        {
        	move_cursor(y_pos, charcount);
        }
    } 
    col++;
    return 0;
}

int k_dbg_print_str_p(char* msg)
{
    if (row > 80 || col > 25) return -1;

    int x = row;
    int y = col*2;
    int charcount = 0;
    
    unsigned char *vram = (char *)0xB8000 + x;

    while (*msg != '\0')
    {   
        int y_pos = CHARS_PER_LINE * y;
        vram[(x++)+y_pos] = *msg++;
        vram[x+y_pos] = 0x04;
        x++;
        charcount++;
        if(y > 2)
        {
            int cursy = CHARS_PER_LINE * (y-(y/2)+1);
            move_cursor(cursy, charcount);
        }
        else
        {
            move_cursor(y_pos, charcount);
        }
    } 
    col++;
    return 0;
}

void move_cursor(int y, int charcount)
{
	unsigned short cursLoc = y - (CHARS_PER_LINE - charcount);
	outb(0x3D4, 14);
	outb(0x3D5, cursLoc >> 8);
	outb(0x3D4, 15);
	outb(0x3D5, cursLoc);
}