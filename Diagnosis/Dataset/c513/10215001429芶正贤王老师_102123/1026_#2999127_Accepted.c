#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void * a,const void * b)
{
    return ( *(long long int*)a - *(long long int*)b);
}

int main()
{
    long long int n;
    scanf("%lld",&n);
    getchar();
    long long int index ;
    long long int a[n];
    for(index = 0;index < n;index++)
        scanf("%lld",&a[index]);
    qsort(a,n,sizeof(long long int),cmpfunc);
    long long int sum = 0;
    for(long long int i = 0;i< n/2 ;i++)
        sum += (a[2*i+1] - a[2*i]);
    printf("%lld",sum);
    return 0;
}