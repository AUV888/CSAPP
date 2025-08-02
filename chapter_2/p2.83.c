#include <stdio.h>
/*The number is the sum of a geometric sequence
* of which the ratio is 2^-k
*/
double B2U_k(int y, int k)
{
    double s = (double)y / ((1 << k) - 1);
    return s;
}

int main()
{
    printf("%lf", B2U_k(3, 4));
    return 0;
}