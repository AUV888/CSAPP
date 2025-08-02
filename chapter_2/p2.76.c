#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *calloc(size_t nmemb, size_t size)
{
    size_t tot_size = nmemb * size;
    if (nmemb == 0 || size > tot_size / nmemb)
        return NULL;
    else
    {
        void *arr = memset((void *)malloc(tot_size), 0, tot_size);
        return arr;
    }
}

int main()
{
    int *a = (int *)calloc(5, 4);
    return 0;
}