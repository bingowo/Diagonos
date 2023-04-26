#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long x,y,r;
    scanf("%lld%lld",&x,&y);
    if((abs(x)+abs(y))%2 == 0)printf("-1");
    else
    {
        r = (log10(abs(x)+abs(y)))/(log10(2))+1;

    }
    printf("%lld",r);
    return 0;
}