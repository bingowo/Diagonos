#include<stdio.h>
#include<stdlib.h>

long long cmp_int(const void* _a,const void* _b)
{
    long long* a=(long long*)_a;
    long long* b=(long long*)_b;
    return *a-*b;
}
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    long long b[10001],k=0;
    while(scanf("%lld",&b[k])!=EOF)
    {
        k++;
    }
    qsort(b,k,sizeof(b[0]),cmp_int);
    for(int i=0;i<k-1;i+=2)
    {
        sum+=b[i+1]-b[i];
    }
    printf("%d",sum);
    return 0;

}
