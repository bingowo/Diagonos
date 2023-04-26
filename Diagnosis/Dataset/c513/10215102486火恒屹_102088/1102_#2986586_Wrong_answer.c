#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    long long n;
    scanf("%lld",&n);
    long long x,y;
    long long m=sqrt(n);
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
    printf("(%d,%d)",x,y);
    return 0;
}
