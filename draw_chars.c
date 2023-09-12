#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 11; row++) {
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      unsigned short colMask = 1 << (15-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}
void print_char_8x12(char c)
{
  c -= 0x20;
  for (char row = 0; row < 8; row++) {
    for (char col = 0; col < 12; col++) {
      unsigned char colBits = font_8x12[c][col];
      unsigned short rowMask = 1 << (8-row); /* mask to select bit associated with bit */
      putchar( (colBits & rowMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}