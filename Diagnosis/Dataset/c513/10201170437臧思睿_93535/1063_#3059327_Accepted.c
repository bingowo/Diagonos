#include <stdio.h>
typedef long long int ll;

int main()
{
    ll x,y,r=0,a,b;
    scanf("%lld %lld",&x,&y);
    while(y!=0)
    {
        a=x/y;
        b=x%y;
        r+=4*a*y;
        x=(y>=b)?y:b;
        y=(y<b)?y:b;
    }
    r+=4*y;
    printf("%lld",r);
    return 0;
}
