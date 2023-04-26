#include<stdio.h>
#include<stdlib.h>

int main()
{
    long long i;
    long long n;
    long long res=0;
    scanf("%lld",&n);
    long long *a = (long long *)malloc(sizeof(long long)*n);
    for (i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long),cmp);
    for (i=0;i<n/2;i++){
        res=res+(a[2*i+1]-a[2*i]);
    }
    printf("%lld",res);
}

long long cmp(const void *_a, const void *_b)
{
    long long * a = (long long *)_a;
    long long * b = (long long *)_b;
    return (*a-*b);
}