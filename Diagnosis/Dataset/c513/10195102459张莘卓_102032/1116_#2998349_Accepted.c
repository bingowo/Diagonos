#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long x, y;
    scanf("%lld %lld",&x, &y);
    x = llabs(x) + llabs(y);
    if(x % 2 == 0) printf("%d\n",x ? -1 : 0);
    else {
        y = 0;
        while(x) {
            ++y;
            x /= 2;
        }
        printf("%lld\n",y);
    }
    return 0;
}