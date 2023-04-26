#include<stdio.h>
#include<stdlib.h>

int getvalue(long long a)
{
    long long res=labs(a);
    while(res>=10) res/=10;
    return res;
}

int cmp(const void*a,const void*b)
{
    long long a0=*(long long*)a,b0=*(long long*)b;
    int v1=getvalue(a0),v2=getvalue(b0);
    if(v1!=v2) return v2-v1;
    else if(a0>b0) return 1;
    else return -1;
}

int main()
{
    int T,N;scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        long long number[N];
        for(int t=0;t<N;t++) scanf("%lld",&number[t]);
        qsort(number,N,sizeof(number[0]),cmp);
        printf("case #%d:\n",i);
        for(int t=0;t<N-1;t++) printf("%lld ",number[t]);
        printf("%lld\n",number[N-1]);
    }

    return 0;
}
