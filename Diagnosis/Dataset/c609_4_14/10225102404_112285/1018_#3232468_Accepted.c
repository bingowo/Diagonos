#include<stdio.h>
#include<stdlib.h>

long long cmp_int(const void* _a,const void* _b)
{
    long long* a=(long long*)_a;
    long long* b=(long long*)_b;
    return *a-*b;
}
long long b[100001];
int main()
{
    long long k=0,n,sum=0;
    scanf("%d",&n);
    while(scanf("%lld",&b[k])!=EOF)
    {
        k++;
    }
    qsort(b,k,sizeof(b[0]),cmp_int);
    for(long long i=0;i<k-1;i+=2)
    {
        sum+=b[i+1]-b[i];
    }
    printf("%d",sum);
    return 0;

}
