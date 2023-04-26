#include <stdio.h>

long long f(long long x, long long y)
{
    if (x < y){
        long long t;
        t = x; x = y; y = t;
    }
    if (y == 0) return 0;
    return 4 * y * (x / y) + f(x, x % y);
}

int main()
{
    long long x, y;
    scanf("%lld %lld", &x, &y);
    printf("%lld", f(x, y));
    return 0;
}