#include <stdio.h>

long long laber(long long x, long long y)
{
    if (x == 0 || y == 0) return 0;
    long long a = find(x, y);
    return x / a + laber(x-a, y - a);
}
long long find(long long x, long long y)
{
    long long i;
    for (i = y;((x % i != 0) || (y % i != 0)) && i != 1;i--);
    return i;
}
int main()
{
    long long x, y;
    scanf("%lld%lld", &x, &y);
    printf("%lld", laber(x*y, find(x, y)));
    return 0;
}