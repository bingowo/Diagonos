#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    int m = *(int*)a, n = *(int*)b;
    int m1 = m, n1 = n;
    int km = 0, kn = 0;
    int i;
    if(m == 0) km = 1;
    if(n == 0) kn =1;
    while(m1 != 0)
    {
        m1 /= 10;
        km++;
    }
    while(n1 != 0)
    {
        n1 /= 10;
        kn++;
    }
    if(km < kn)
        return 1;
    if(km > kn)
        return -1;
    if(km == kn)
    {
        if(m > n)
            return 1;
        if(m < n)
            return -1;
        if(m == n)
            return 0;
    }
}

int main()
{
    int i = 0;
    int t;
    int *a = (int*)malloc(1000005*sizeof(int));
    while(scanf("%d", &a[i]) != EOF)
        i++;
    qsort(a,i,sizeof(int),cmp);
    for(t=0; t<i; t++)
        printf("%d ", a[t]);

    return 0;
}
