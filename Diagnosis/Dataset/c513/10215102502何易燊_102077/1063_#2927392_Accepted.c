#include <stdio.h>

int main()
{
    long long x,y;
    long long spend = 0;
    scanf("%lld %lld",&x,&y);
    if (x>=y) {x^=y, y^=x, x^=y;}
    if (y%x==0) spend = 4*x*(y/x);
    else
        while (x&&y)
        {
            if (x>=y) {x^=y; y^=x; x^=y;}
            spend += x*4;
            y -= x;
        }
    printf("%lld\n",spend);
    return 0;
}