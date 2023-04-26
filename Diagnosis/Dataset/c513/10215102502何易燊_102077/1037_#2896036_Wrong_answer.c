#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    long long* c = (long long*)a; long long* d = (long long*)b;
    return (*c>*d)?-1:1;
}

long long getmin(long long a,long long b)
{
    return (a>b)? b: a;
}

main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long* a = (long long*)malloc(n*sizeof(long long));
    for (int i=0;i<n;i++) scanf("%lld",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    long long min = (m-1)*a[0], res;
    for (int i=1;i<m;i++) min -= a[i];
    res = min;
    for (int i=m;i<n;i++)
    {
        res = res-2*a[i-m]+3*a[i-m+1]-a[i];
        min = (res<min)? res: min;
    }
    printf("%lld\n",min);
    return 0;
}