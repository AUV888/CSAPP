#include <stdio.h>

int any_odd_one(unsigned x)
{
    return !!(x & 0xAAAAAAAAu);
}

int main()
{
    printf("%d",any_odd_one(0x55555555u));
    return 0;
}