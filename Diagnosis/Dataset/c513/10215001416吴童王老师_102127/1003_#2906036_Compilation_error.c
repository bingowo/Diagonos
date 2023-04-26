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
int inc(const void *nx,const void *ny)
{
    const void x,y;
    nx=numberof1(x);
    ny=numberof1(y);
    return *(long long *nx)>*(long long *ny)?1:-1;
}
int main()
{
    int T,N;
    long long a[1000];
    long long b[1000];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        printf("case #%d:\n",i);
        int j=0;
        int n=N;
        while(N>0)
        {
            scanf("%lld ",&a[j]);
            b[j]=numberof1(a[j]);
            j++;
            N--;
        }
        qsort(b,n,sizeof(long long),inc);
        for(int k=0;k<n;k++)
        {
            printf("%lld ",a[k]);
        } 
        printf("\n");
    }
   return 0;
}