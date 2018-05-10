#include "framebuffer.h"
#include "io.h"

/* The memory mapped address for the framebuffer */
char* fb = (char*)0x000B8000;
unsigned short fb_current_pos = 0;

/** fb_move_cursor:
 *  Moves the cursor of the framebuffer to the given position
 *
 *  @param pos The new position of the cursor
 */
void fb_move_cursor(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}

/** fb_write_cell:
*  Writes a character with the given foreground and background to position i
*  in the framebuffer.
*
* Value Color
*  0   Black
*  1   Blue
*  2   Green
*  3   Cyan
*  4   Red
*  5   Magenta
*  6   Brown
*  7   Light Grey
*  8   Dark Grey
*  9   Light Blue
*  10  Light Green
*  11  Light Cyan
*  12  Light Red
*  13  Light Magenta
*  14  Light Brown
*  15  White
*
*  @param i  The location in the framebuffer
*  @param c  The character
*  @param fg The foreground color
*  @param bg The background color
*/
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

/** write:
*  Writes a character buffer
*
*  @param buf The character buffer
*  @param len The length of the buffer
*/
void write(char *buf, unsigned int len)
{
    unsigned short i;
    for(i = 0; i < len; i++)
    {
        fb_write_cell(fb_current_pos, buf[i], 0, 15);
        fb_current_pos += 2;
    }
}