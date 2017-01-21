#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

void fb_move_cursor(unsigned short pos);

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);

void write(char *buf, unsigned int len);

#endif /* FRAMEBUFFER_H */