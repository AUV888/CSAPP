#include <stdio.h>
#include <limits.h>

// p+p=n -> pos overfl
// n+n=p -> neg overfl
// 正数+负数永远不会overflow
int saturating_add(int x, int y)
{
    int sum = x + y;
    int sx = x >> 31;
    int sy = y >> 31;
    int ss = sum >> 31;
    int pos_overfl = ~sx & ~sy & ss;
    int neg_overfl = sx & sy & ~ss;
    int not_overfl = ~(pos_overfl | neg_overfl);
    return (pos_overfl & INT_MAX) | (not_overfl & sum) | (neg_overfl & INT_MIN);
}

int main(void)
{
    return 0;
}