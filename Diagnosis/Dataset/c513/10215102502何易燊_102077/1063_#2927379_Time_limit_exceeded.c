#include <stdio.h>

int main()
{
    long long x,y;
    long long spend = 0;
    scanf("%lld %lld",&x,&y);
    while (x&&y)
    {
        if (x>=y) {x^=y; y^=x; x^=y;}
        spend += x*4;
        y -= x;
    }
    printf("%lld\n",spend);
    return 0;
}