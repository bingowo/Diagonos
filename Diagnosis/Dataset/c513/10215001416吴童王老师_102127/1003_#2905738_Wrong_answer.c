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
int inc(const void *x,const void *y)
{
    return * (long long *)x> * (long long *)y?1:-1;
}
int main()
{
    int T,N;
    long long a[1000];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        printf("case#%d:\n",i);
        while(N>0)
        {
            int j=0;
            scanf("%lld ",&a[j]);
            j++;
            N--;
        }
        qsort(a,N,sizeof(int),inc);
        for(int k=0;k<N;k++)
        {
            printf("%lld",a[k]);
        }
    }
   return 0;
}