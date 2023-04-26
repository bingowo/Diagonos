#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
long long int max(long long int x,long long int y)
{
    if(x>y)
        return x;
    else
        return y;
}
long long int min(long long int x,long long int y)
{
    if(x>y)
        return y;
    else
        return x;
}
long long int slo(long long int n,long long int m)
{   long long int s;
    if(n==m)
        return n*4;
    else
    {
        s=4*min(n,m);
        return s+slo(llabs(n-m),min(n,m));
    }
}
int main()
{
    long long int n,m;
    scanf("%lld%lld",&n,&m);
    printf("%lld",slo(n,m));
    return 0;
}
