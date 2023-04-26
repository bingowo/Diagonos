#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long farm( long long x, long long y)
{
    if( x == y )
        return 4 * x;
    if( x == 1 )
        return 4 * y;
    long long min = y - x < x ? y - x : x;
    long long max = y - x > x ? y - x : x;
    return farm( min, max );
}

int main()
{
    long long x, y;
    scanf("%lld%lld",&x, &y);
    printf("%lld",farm(x, y));
}
