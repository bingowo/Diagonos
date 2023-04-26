#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    long long int x,y;
    scanf("%lld %lld",&x,&y);
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
    printf("%lld\n",ans*4);

    return 0;
}



