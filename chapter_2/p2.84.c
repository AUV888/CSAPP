#include <stdio.h>

unsigned f2u(float x)
{
    unsigned result;
    memcpy(&result, &x, sizeof(float));
    return result;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    /* Get the sign bits */
    unsigned sx = ux >> 31; // -1 when neg, 0 when pos
    unsigned sy = uy >> 31;
    /* Give an expression using only ux, uy, sx, and sy */
    return 0;
}

int main()
{

    return 0;
}