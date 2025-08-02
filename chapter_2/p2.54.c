#include <stdio.h>
#include <limits.h>

int main(void)
{
	int x = INT_MAX;
	printf("x=%d\n(float)x=%f\n(int)(float)x=%d\n", x, (float)x, (int)(float)x);
	return 0;
}
