#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a , const void *b)
{
    long long a1=*(long long *)a,b1=*(long long *)b;
    int ta=0,tb=0,fa=1,fb=1;
    if(a1<0)
    {
        fa=-1;
        a1=-a1-1;
    }
    if(b1<0)
    {
        fb=-1;
        b1=-b1-1;
    }
    while(a1>0)
    {
        if(a1%2==1)  ta++;
        a1/=2;
    }
    while(b1>0)
    {
        if(b1%2==1)  tb++;
        b1/=2;
    }
    if(fa==-1)  ta=64-ta;
    if(fb==-1)  tb=64-tb;
    if(ta>tb)  return -1;
    else if(ta<tb)  return 1;
    else if(*(long long *)a>*(long long *)b)  return 1;
    else return -1;
}
int main()
{
    int T,N,i,j,k,t;
    long long num[10010];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            scanf("%lld",&num[j]);
        }
        qsort(num,N,sizeof(long long),cmp);
        printf("case #%d:\n",i);
        printf("%lld",num[0]);
        for(j=1;j<N;j++)
        {
            printf(" %lld",num[j]);
        }
        printf("\n");
    }
    return 0;
}