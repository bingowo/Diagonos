#include <stdio.h>
typedef long long int ll;

int main()
{
    ll x,y,r=0,i;
    scanf("%lld %lld",&x,&y);
    if(y==1){printf("%lld",4*x);}
    else
    {
        while(x>y)
        {
            r+=4*y;
            i=x;
            x=((x-y)>=y)?(x-y):y;
            y=((i-y)<y)?(i-y):y;
        }
        r+=4*y;
        printf("%lld",r);
    }

    return 0;
}
