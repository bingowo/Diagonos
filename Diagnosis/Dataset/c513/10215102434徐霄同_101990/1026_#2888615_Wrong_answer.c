#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void *a,const void *b)
{
    int* a0=(int*)a;
    int* b0=(int*)b;
    return a0-b0;
}
int main()
{
    int n,i;
    int a[100000];
    long long x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    x=0;
    for(i=0;i<n/2;i++)
        x=x+fabs(a[2*i]-a[2*i+1]);
    printf("%lld",x);
    return 0;
}
