#include<stdio.h>
#include<stdlib.h>
int numberof1(long long i)
{
    int count=0;
    while(i)
    {
        count++;
        i=(i-1)&i;
    }
    return count;
}
int inc(long long x,long long y)
{
    int nx=numberof1(x);
    int ny=numberof1(y);
    return nx>ny?1:-1;
}
int main()
{
    int T,N,a[1000];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        while(N)
        {
            int j=0;
            scanf("%lld",a);
            j++;
            N--;
        }
        qsort(a,N,sizeof(int),inc);
        for(int k=0;k<N;k++)
        {
            printf("case #i:\n%lld",a[k]);
        }
    }
   return 0;
}