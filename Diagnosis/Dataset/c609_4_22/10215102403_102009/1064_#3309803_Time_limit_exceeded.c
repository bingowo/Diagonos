#include<stdio.h>

int main()
{
    long long int x,y,t,labor=0;
    scanf("%lld %lld",&x,&y);
    if(x<y)
    {
        t=x; x=y; y=t;
    }
    while(y>0)
    {
        labor+=4*y;
        x-=y;
        if(x<y)
        {
            t=x; x=y; y=t;
        }
    }
    printf("%lld",labor);
    return 0;
}
