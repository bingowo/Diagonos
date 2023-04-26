#include <stdio.h>
typedef long long int ll;

int main()
{
    int i;
    ll x,y,r=0;
    scanf("%lld %lld",&x,&y);
    while(x>y)
    {
        r+=4*y;
        i=x;
        x=((x-y)>=y)?(x-y):y;
        y=((i-y)<y)?(i-y):y;
    }
    r+=4*y;
    printf("%lld",r);
    return 0;
}
