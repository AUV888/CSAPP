#include <stdio.h>
/* round to zero
 * for negative nums, add 2^k-1, so result = floor（x/2^k） + 1 - 1/2^k
 * which is round to zero
 */
int divide_power2(int x, int k)
{
    int sign = x >> 31;
    x += sign & ((1 << k) - 1);
    return x >> k;
}

int main()
{
    printf("%d", divide_power2(-4, 1));
    return 0;
}