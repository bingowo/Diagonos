#include <stdio.h>
#include <stdlib.h>

long long int newton(long long int x,long long int y)
{
    if(x<y)
    {
        long long temp=x;
        x=y;
        y=temp;
    }
    if(y==0) return 0;
    long long v;
    v=x/y*y*4+newton(y,x%y);
    return v;
}

int main()
{
    long long int x,y;
    long long int v;
    scanf("%lld",&x);
    scanf("%lld",&y);
    v=newton(x,y);
    printf("%lld\n",v);
}
