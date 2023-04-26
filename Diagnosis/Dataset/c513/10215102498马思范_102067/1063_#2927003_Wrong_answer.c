#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long x,y;
    long long t;
    int a,b;
    scanf("%lld%lld",&x,&y);
    if(x==y)
    {
        t=4*x;
    }
    else
    {do
        {
            a=x/y;
            t=t+a*y*4;
            b=x%y;
            x=y;
            y=b;
        } while(b!=0);
    }
    printf("%lld",t);
}