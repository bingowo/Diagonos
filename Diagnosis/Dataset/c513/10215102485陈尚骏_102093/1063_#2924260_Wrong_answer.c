#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x,y;
    long long v=0;
    long long t=1;
    scanf("%lld %lld",&x,&y);
    while(x!=0&&y!=0)
    {
        if(x>y)
        {
            v+=4*y;
            t=x/y;
            x=x%y;
        }
        else if(x<=y)
        {
            v+=4*x;
            t=y/x;
            y=y%x;
        }
    }
    v=v*t;
    printf("%lld",v);
    return 0;
}
