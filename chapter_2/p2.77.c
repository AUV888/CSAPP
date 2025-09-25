#include <stdlib.h>

int main()
{
    int x = 0x12345678;
    int res = 0;
    // K = 17
    res = x << 4 + x;
    // K = -7
    res = x - x << 3;
    // K = 60
    res = x << 6 - x << 2;
    // K = -112
    res = x << 4 - x << 7;
    return 0;
}