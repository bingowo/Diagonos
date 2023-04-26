#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long long mysqrt(long long n)
{
    long long m=sqrt(n);
    if(!(n>=m*m&&n<=(m+1)*(m+1)))
       m=m-1;
    return m;
}
int main()
{
    long long n;
    scanf("%lld",&n);
    long long x,y;
    long long m=mysqrt(n);
    if(m%2==0)
    {
        x=-m/2;
        y=-m/2;
        if(n<=m*m+m) x=x+(n-m*m);
        else {x=x+m;y=y+n-m*m-m;}
    }
    else
    {
        x=(m-1)/2;
        y=(m+1)/2;
        if(n<=m*m+m) x=x-(n-m*m);
        else {x=x-m;y=y-(n-m*m-m);}
    }
    printf("(%lld,%lld)",x,y);
    return 0;
}
