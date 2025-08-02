#include <stdio.h>
#include <string.h>

/* WARNING: The following code is buggy
* Because size_t is a type of unsigned int

void copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes - sizeof(val) >= 0)
        memcpy(buf, (void *)&val, sizeof(val));
}
*/

void copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes >= sizeof(val) && maxbytes > 0)
        memcpy(buf, (void *)&val, sizeof(val));
}

int main()
{
    return 0;
}