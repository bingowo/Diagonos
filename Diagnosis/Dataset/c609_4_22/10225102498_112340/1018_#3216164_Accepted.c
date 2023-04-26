#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    int m = *(int*)a, n = *(int*)b;
    return n-m;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int x[n];
    for(i=0; i<n; i++)
        scanf("%d", &x[i]);
    qsort(x,n,sizeof(int),cmp);

    int sum = 0;
    for(i=0; i<n; i+=2)
        sum += x[i] - x[i+1];
    printf("%d", sum);

    return 0;
}
