#include <stdio.h>
#include <stdlib.h>
long long cmp(const void * _a,const void * _b)
{
    return ( *(long long*)_a - *(long long*)_b );
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
