#include <stdio.h>
#include <stdlib.h>

int gethigh(long long a)
{
    long long b = (a>=0)?a:-a;
    while (b/10>0) b /= 10;
    return b;
}

int cmp(const void* a,const void* b)
{
    long long* c = (long long*)a; long long* d = (long long*)b;
    if (gethigh(*c)!=gethigh(*d)) return gethigh(*d)-gethigh(*c);
    else return (*c>*d)?1:-1;
}

main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        long long num[10001] = {};
        int n;
        scanf("%d",&n);
        for (int j=0;j<n;j++) scanf("%lld",&num[j]);
        qsort(num,n,sizeof(num[0]),cmp);
        printf("case #%d:\n",i);
        for (int j=0;j<n;j++) printf("%lld ",num[j]);
        printf("\n");
    }
    return 0;
}