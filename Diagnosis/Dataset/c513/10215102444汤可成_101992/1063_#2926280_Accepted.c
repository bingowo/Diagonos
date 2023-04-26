#include <stdio.h>
#include <stdlib.h>

long long value(long long x, long long y)
{
    if(x == y) return 4*x;
    else
    {
        if(x*y == 0) return 0;
        if(x < y)
        {
            long long int tmp = y/x;
            return tmp*value(x,x) + value(y-tmp*x, x);
        }
        else
        {
            long long int tmp = x/y;
            return tmp*value(y,y) + value(x-tmp*y, y);
        }
    }
}

int main()
{
    long long x = 0, y = 0;
    scanf("%lld %lld",&x, &y);
    printf("%lld", value(x,y));
    return 0;
}
