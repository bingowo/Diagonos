#include<stdio.h>

long long max(long long a, long long b)
{
    return (a>b)?a:b;
}

long long min(long long a, long long b)
{
    return (a<b)?a:b;
}

int main()
{
    long long x,y,labor=0;
    scanf("%lld %lld",&x,&y);
    x=max(x,y); y=min(x,y);
    while(y>0)
    {
        labor+=4*y;
        x-=y;
        x=max(x,y);
        y=min(x,y);
    }
    printf("%lld",labor);
    return 0;
}