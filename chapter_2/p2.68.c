#include <stdio.h>

int lower_one_mask(int n)
{
    // More robust method
    int res = 1 << (n - 1);
    res |= res >> 1;
    res |= res >> 2;
    res |= res >> 4;
    res |= res >> 8;
    res |= res >> 16;
    return res;

    // UB when n = 32
    /*
    return (2 << (n - 1)) - 1;
    */
}

int main()
{
    printf("%x", lower_one_mask(32));
    return 0;
}