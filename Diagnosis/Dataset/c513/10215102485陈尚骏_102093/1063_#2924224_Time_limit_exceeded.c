#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x,y;
    long long v=0;
    scanf("%lld %lld",&x,&y);
    while(x!=0&&y!=0)
    {
        if(x>y)
        {
            v+=4*y;
            x-=y;
        }
        else if(x<=y)
        {
            v+=4*x;
            y-=x;
        }
    }
    printf("%lld",v);
    return 0;
}
