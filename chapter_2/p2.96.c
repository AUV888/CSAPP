#include <stdio.h>
#include "util.h"

/*Round towards zero
 */

int float_f2i(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    int E = (int)exp - 127;
    if (!(E < 31 || E == 31 && !frac && sign)) // Overflow or NaN
    {
        return 0x80000000;
    }
    if (E < 0) // Denormalized and number less than 1
    {
        return 0;
    }
    /*Calculate absolute value*/
    frac += 0x800000;
    if (E < 23) // Right shift
    {
        frac >>= (23 - E);
    }
    else // Left shift
    {
        frac <<= (E - 23);
    }
    if (sign == 1) // Negative Normalized
    {
        frac = ~frac + 1;
    }
    return (int)frac;
}

int main()
{
    printf("%d\n", float_f2i(f2fb(-2.5)));
    return 0;
}