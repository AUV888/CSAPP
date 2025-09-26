#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    int mov = i << 3;        // bit = byte * 8
    x = x & ~(0xFF << mov);  // clear the area to be replaced
    x = x | ((int)b << mov); // replace the byte
    return x;
}

int main(void)
{
    printf("result=%x\n", replace_byte(0x12345678, 0, 0xAB));
    return 0;
}