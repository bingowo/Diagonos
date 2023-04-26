#include <stdio.h>
#include <stdlib.h>

int num(long long n)
{
    int num = 0;
    for (int i=0;i<64;i++)
    {
        if (n&1) num++;
        n >>= 1;
    }
    return num;
}

int cmp(const void* a,const void* b)
{
    long long* a_ = (long long*)a;
    long long* b_ = (long long*)b;
    if (num(*a_)!=num(*b_)) return num(*b_)>num(*a_)? 1: -1;
    return *a_>=*b_? 1 : -1;
}

main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        long long a[10000];
        for (int j=0;j<n;j++) scanf("%lld",&a[j]);
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for (int j=0;j<n;j++) printf("%d ",a[j]);
        printf("\n");
    }
    system("pause");
    return 0;
}