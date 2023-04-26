#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a, const void * b)
{
    return *(int *)a - *(int *)b;
}

int cmp2(const void *a, const void * b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i ; i < T ; i++)
    {
        int n, ans = 0;
        scanf("%d",&n);
        int a[n], b[n];
        for(int i = 0 ; i < n ; i++)
            scanf("%d",&a[i]);
        for(int i = 0 ; i < n ; i++)
            scanf("%d",&b[i]);
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp2);
        for(int i = 0 ; i < n ; i++)
            ans += a[i] * b[i];
        printf("case #%d:\n%d\n",i,ans);
    }
}
