#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(long long *pa, long long *pb)
{
    long long t = *pa;
    *pa = *pb;
    *pb = t;
}

int main()
{
    long long x, y;
    scanf("%lld%lld", &x, &y);
    if (x > y)
        swap(&x, &y);
    long long ans = 0;
    while (x)
    { // 每次均以为最短边
        long long a = y / x;
        ans += 4 * x * a;
        y %= x;
        swap(&x, &y);
    }
    printf("%lld", ans);
    return 0;
}