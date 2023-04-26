#include <stdio.h>
#include <stdlib.h>
int cmp(const void * _a,const void * _b)
{
    long long *a=(long long *)_a;
    long long *b=(long long *)_b;
    if(a>b) return  1;
    else return -1;
}
int main()
{
    int n;scanf("%d",&n);
    long long arr[n];
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    qsort(arr,n,sizeof(long long),cmp);
    for(int i=0;i<n;i+=2)
    {
        sum=sum+arr[i+1]-arr[i];
    }
    printf("%lld\n",sum);
    return 0;
}
