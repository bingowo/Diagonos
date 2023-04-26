#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long n, x, y;
    scanf("%lld",&n);
    long long a = (long long) sqrt((double)n);
    if(a * a > n) --a;
    if(a % 2) {
        x = a / 2;   y = x + 1;
        if(n - a*a <= a) x -= n - a*a;
        else {
            x -= a;
            y -= n - a * (a+1);
        }
    }else {
        x = y = -a / 2;
        if(n - a*a <= a) x += n - a*a;
        else {
            x += a;
            y += n - a * (a+1);
        }
    }
    printf("(%lld,%lld)\n",x,y);
    return 0;
}
