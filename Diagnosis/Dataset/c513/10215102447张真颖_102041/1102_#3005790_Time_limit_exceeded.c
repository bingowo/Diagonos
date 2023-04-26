#include <stdio.h>
#include <stdlib.h>

long long f(long long n)
{
    long long t;
    for(t=1;!(t*(t+1)<=n&&(t+1)*(t+2)>=n);t++);
    return t;
}

int main()
{
    long long n=0;
    scanf("%lld",&n);
    long long m=f(n),x0=0,y0=0,signx=1,signy=-1;
    for(long long i=1;i<m+1;i++)
    {
        signx*=-1,signy*=-1;
        x0+=signx*i;
        y0+=signy*i;
    }
    long long d=n-m*(m+1),x=0,y=0;
    if(d<=m+1)
    {
        x=x0;
        y=x0>0?y0+d:y0-d;
    }
    else
    {
        y=y0+(m+1);
        d-=(m+1);
        x=y0>0?x0-d:x0+d;
    }
    printf("(%lld,%lld)",x,y);
    return 0;
}