#include <stdio.h>
#include <stdlib.h>

long long min(long long x, long long y)
{
    if(x<y){return x;}
    else{return y;}
}

long long max(long long x, long long y)
{
    if(x>y){return x;}
    else{return y;}
}

int main()
{
    long long x = 0,y = 0;
    scanf("%lld%lld",&x,&y);

    long long ans = 0;
    while((x>0)&&(y>0))
    {

        if(x>y)
        {
            if(x%y==0)
            {
                ans+=4*x/y;
                break;
            }
            else
            {
                ans+=4*y;
                x-=y;
            }
        }
        else
        {
            if(y%x==0)
            {
                ans+=4*y/x;
                break;
            }
            else
            {
                ans+=4*x;
                y-=x;
            }
        }


        //printf("%lld\n",ans);
    }

    printf("%lld",ans);


    return 0;
}
