#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int f(long long int x,long long int y)
{
    long long int ans=0;
    while(x!=y)
    {
        if(x>y)
        {
            x=x-y;
            ans+=y;
        }
        else
        {
            y=y-x;
            ans+=x;
        }
    }
    if(x==y) ans+=x;
    return ans*4;
}

int main()
{

    long long int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld\n",f(x,y));

    return 0;
}



