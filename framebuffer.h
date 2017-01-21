#ifndef INCLUDE_FRAMEBUFFER_H
#define INCLUDE_FRAMEBUFFER_H

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

/* The memory mapped address for the framebuffer */
char* fb = (char*)0x000B8000;
unsigned short fb_current_pos = 0;

void fb_move_cursor(unsigned short pos);

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);