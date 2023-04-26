#include <stdio.h>
#include <string.h>

long long fuc(long long, long long);

int main()
{
    long long x, y, v;
    scanf("%lld%lld", &x, &y);
    v = fuc(x, y);
    printf("%lld", v);
    return 0;
}

long long fuc(long long x, long long y)
{
    long long v;
    if(x < y)
    {
        long long temp = x;
        x = y;
        y = temp;
    }

    if(x == 0 || y == 0)  return 0;

    v = fuc(x%y, y) + x/y * 4 * y;

    return v;
}