#include <stdio.h>
#include <stdlib.h>

int high(long long int a)
{
    long long int ret[100],i;
    for(i=0;i<=100;i++) ret[i]=0;
    if(a<0) a=-a;
    if(a==0) return -1;
    for(i=0;a>0;i++)
    {
        ret[i]=a%10;
        a/=10;
    }
    return ret[i-1];
}

int cmp(const void* a,const void *b)
{
    long long int d1,d2;
    d1=*((long  long int*)a),d2=*((long long int*)b);
    int t=high(d2)-high(d1);
    if(t==0)
    {
        if(d1>d2) t=1;
        else t=-1;
    }
    return t;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int n,j;
        scanf("%d",&n);
        long long int num[20000];
        for(j=0;j<n;j++) scanf("%lld",&num[j]);
        qsort(num,n,sizeof(num[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n-1;j++) printf("%lld ",num[j]);
        printf("%lld\n",num[n-1]);
    }
    return 0;
}

