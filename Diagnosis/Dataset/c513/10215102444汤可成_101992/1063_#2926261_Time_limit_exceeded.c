#include <stdio.h>
#include <stdlib.h>

long long value(long long x, long long y)
{
    if(x == y) return 4*x;
    else
    {
        if(x < y)
            return value(x, x)+value(y-x, x);
        else
            return value(y, y)+value(x-y, y);
    }
}

int main()
{
    long long x = 0, y = 0;
    scanf("%lld %lld",&x, &y);
    printf("%lld", value(x,y));
    return 0;
}
