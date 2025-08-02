#include <stdio.h>

typedef unsigned packed_t;

// Failed attempt. It returned a 4 bit unsigned number.
/*
int xbyte(packed_t word, int bytenum)
{
    return (word >> (bytenum << 3)) & 0xFF;
}
*/
int xbyte(packed_t word, int bytenum) // 0xFA018211
{
    word = (word >> (bytenum << 3)) & 0xFF; // 0x000000FA
    return (word & 0x7F) - (word & 0x80);
}

int main()
{
    printf("%d", xbyte(0x11018211, 3));
    return 0;
}