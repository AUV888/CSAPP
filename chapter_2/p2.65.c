#include <stdio.h>
/*
 *Use xor(^) to count the num of '1'
 *e.g. for 0b1001, 1^0^0^1=0; for 0b1101, 1^1^0^1=1
 */

int odd_ones(unsigned x)
{
    x = x ^ (x >> 16); // the new x = (x_left16)^(x_right16)
    /*
     *Let the 32 bits of x be b31 b30 ... b0
     *When right shift 16, b31 to b16 remain unchanged,
     *but b15(new) = b15 ^ b31, ... b0(new) = b16 ^ b0
     *Therefore, the lower 16 bits contains the information of former 32 bits
     *Repeat this procedure until we "compress" it to 1 bit
     */
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    /*
     *b0(latest) = b31 ^ ... ^ b0
     */
    return x & 1;
}

int main()
{
    printf("%d", odd_ones(0b11011111u));
    return 0;
}