#include<stdio.h>
#include<string.h>
long long cmp(const void* a,const void* b)
{
    char bita[64],bitb[64];
    long long i,sum1,sum2,c,d;
    sum1=0;
    sum2=0;
    c=*(long long*)a;
    d=*(long long*)b;
    for(i=0;i<64;i++)
    {
        bita[i]=c&1;
        c=c>>1;
    }
    for(i=0;i<64;i++)
    {
        if(bita[i]==1)
            sum1++;
    }
    for(i=0;i<64;i++)
    {
        bitb[i]=d&1;
        d=d>>1;
    }
    for(i=0;i<64;i++)
    {
        if(bitb[i]==1)
            sum2++;
    }
    if(sum1<sum2)
        return 1;
    else if(sum1>sum2)
        return -1;
    else
    {
        if(*(long long*)a<*(long long*)b)
            return -1;
        else if(*(long long*)a>*(long long*)b)
            return 1;
        else
            return 0;
    }
}
int main()
{
    long long *a,j,N,T,i;
    scanf("%lld",&T);
    for(i=0;i<T;i++)
    {
        scanf("%lld",&N);
        a=(long long*)malloc(N*sizeof(long long));
        for(j=0;j<N;j++)
        {
            scanf("%lld",&a[j]);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N;j++)
        {
            printf("%lld ",a[j]);
        }
        printf("\n");
    }
    return 0;
}
