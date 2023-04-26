#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int* a;
int m, n;

int cmp(const void* x, const void* y)
{
    int p = *(int*)x, q = *(int*)y;
    int i;
    for(i=0; i<m; i++)
    {
        if(p == a[i])
            return -1;
        if(q == a[i])
            return 1;
    }
    return p - q;
}

int main()
{
    int i;
    scanf("%d", &m);
    a= (int*)malloc(m*sizeof(int));
    for(i=0; i<m; i++)
        scanf("%d", &a[i]);
    scanf("%d", &n);
    int b[n];
    for(i=0; i<n; i++)
        scanf("%d", &b[i]);

    qsort(b,n,sizeof(int),cmp);
    for(i=0; i<n; i++)
        printf("%d ", b[i]);

    return 0;
}
