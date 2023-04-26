#include <stdio.h>
#include <stdlib.h>

long long int newton(long long int x,long long int y)
{
    long long int temp;
    long long int v;
    temp=x-y;
    while(temp)
    {
        v+=4*y;
        if(temp>y)
        {
            x=temp;
        }
        else
        {
            y=temp;
        }
        v+=newton(x,y);
    }
}

int main()
{
    long long int x,y;
    long long int v;
    scanf("%lld",x);
    scanf("%lld",y);
    v=newton(x,y);
    printf("%lld\n",v);
}
