#include <stdio.h>
#include <string.h>
#include "util.h"

float_bits float_negate(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7fffff;
    /*test NaN*/
    if (exp == 0xFF && frac)
    {
        return f;
    }
    return ((~sign) << 31) | (exp << 23) | frac;
}

int main()
{
    float ff = 7.1352;
    float_bits fb = f2fb(ff);
    printf("%f", fb2f(float_negate(fb)));
    return 0;
}