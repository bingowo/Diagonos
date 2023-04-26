#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b);
int main()
{
    int n;
    scanf("%d",&n);
    long x[n];
    for (int i=0;i<n;i++)
        scanf("%ld",&x[i]);
    qsort(x,n,sizeof(long),cmp);
    long ans=0;
    for (int i=1;i<n;i+=2)
    {
        ans+=(x[i]-x[i-1]);
    }
    printf("%ld",ans);
}
int cmp(const void* a,const void* b)
{
    return (*(int*)a)-(*(int*)b);
}