#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x,y;
    long long v=0;
    scanf("%lld %lld",&x,&y);
    while(x!=0&&y!=0)
    {
        long long t=1;
        if(x>y)
        {
            t=x/y;
            v+=4*y*t;
            x=x%y;
        }
        else if(x<=y)
        {
            t=y/x;
            v+=4*x*t;
            y=y%x;
        }
    }
    printf("%lld",v);
    return 0;
}
