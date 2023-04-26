#include <stdio.h>

long long laber(long long x, long long y)
{
    if (x % y == 0) return 4 * y * (x / y);
    return 4 * y * (x / y) + laber(y, x - y);
}

int main()
{
    long long x, y;
    scanf("%lld%lld", &x, &y);
    printf("%lld", laber(x, y));
    return 0;
}