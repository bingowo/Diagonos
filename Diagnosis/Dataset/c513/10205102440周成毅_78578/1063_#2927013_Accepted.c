#include <stdio.h>

long long farm(long long x, long long y)
{
    if(x%y==0)
        return x/y*4*y;
    else
        return x/y*4*y+farm(y, x%y);
}

int main()
{
    long long x, y;
    scanf("%lld %lld",&x, &y);
    printf("%lld\n", farm(x, y));
    return 0;
}