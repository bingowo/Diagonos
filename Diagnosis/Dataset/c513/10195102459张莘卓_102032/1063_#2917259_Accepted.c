#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x, y;
    scanf("%lld %lld",&x, &y);
    long long c = 0;
    while(y != 0) {
        c += 4 * y * (x / y);
        long long t = x % y;
        x = y;  y = t;
    }
    printf("%lld\n",c);
    return 0;
}