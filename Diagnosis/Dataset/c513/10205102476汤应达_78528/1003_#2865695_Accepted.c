#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{
    long long a0=0,b0=0,d=1;
    long long a1=*(long long*)a,b1=*(long long*)b;
    for(int i=0;i<64;i++)
    {
        if(a1&d) a0++;
        if(b1&d) b0++;
        d<<=1;
    }
    if(a0>b0) return -1;
    else if(a0<b0) return 1;
    else
    {
        if(a1>b1) return 1;
        else return -1;
    }
}

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;scanf("%d",&n);
        long long num[n];
        for(int p=0;p<n;p++) scanf("%lld",&num[p]);
        qsort(num,n,sizeof(long long),cmp);
        printf("case #%d:\n",i);
        for(int p=0;p<n;p++) printf("%lld ",num[p]);
        printf("\n");
    }

    return 0;
}