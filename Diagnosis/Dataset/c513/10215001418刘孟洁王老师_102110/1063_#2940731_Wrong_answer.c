#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long p;
void power(long long x,long long y)
{
    if(!y)return ;
    else if(x == y)
    {
        p += (p+4*y);
        return ;
    }
    else
    {
        long long num = x/y;
        p += (p+num*4*y);
        power(y,x%y);
    }
}
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    power(x,y);
    printf("%lld\n",p);
    return 0;
}
