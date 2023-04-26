#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    long long ans=0;
    if(x==y) ans+=4*x;
    else if(x%y==0)
    {
        ans=y*4*(x/y);
    }
    else if(y%x==0)
    {
        ans=x*4*(y/x);
    }
    else
    {
        while(x!=y)
        {
            if(x>y)
            {
                x-=y;
                ans+=y*4;
            }
            else
            {
                y-=x;
                ans+=x*4;
            }
        }
        ans+=x*4;
    }
    printf("%lld\n",ans);
    return 0;
}
