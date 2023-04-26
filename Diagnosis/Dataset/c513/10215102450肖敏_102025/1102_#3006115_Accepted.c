#include <stdio.h>
typedef long long ll;
int main() {
    ll a;
    scanf("%lld",&a);
    ll b=0;
    while ((b+1)*(b+1)<=a)
    {
        b++;
    }
    ll c;
    c=a-b*b;
    ll x,y;
    if(b%2)//奇数
    {
        x=b/2;
        y=b/2+1;
        if(c>b)
        {
            x-=b;
            y-=c-b;
        }
        else
        {
            x-=c;
        }
    }
    else
    {
        x=-b/2;
        y=-b/2;
        if(c>b)
        {
            x+=b;
            y+=c-b;
        }
        else
        {
            x+=c;
        }
    }
    printf("(%lld,%lld)\n",x,y);
    return 0;
}
