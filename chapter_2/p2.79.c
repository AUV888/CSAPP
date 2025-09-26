#include <stdio.h>

/* calculate x-x/4 to prevent overflow
 * pos x -> quarter should ceiling
 * neg x -> quarter should floor
 */
int mul3div4(int x)
{
    int sign = x >> 31; // arithmetic right shift
    int quarter = (x + (~sign & 3)) >> 2;
    return x - quarter; // round to zero
}

int main()
{
    printf("%d", mul3div4(2));
    return 0;
}