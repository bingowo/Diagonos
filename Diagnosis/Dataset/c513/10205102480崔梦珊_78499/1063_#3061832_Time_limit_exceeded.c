#include<stdio.h>
#include<math.h>
typedef unsigned long long ll;
ll f(ll x,ll y)
{
    if(x==y) return x*4;
    ll max,min;
    ll ans=0;
    if(x>y)
    {
        max=x;
        min=y;
    }
    if(x<y)
    {
        max=y;
        min=x;
    }
    while(min!=max)
    {
        ans+=min*4;
        max=max-min;
        if(max<min)
        {
            ll temp=max;
            max=min;
            min=temp;
        }
    }
    ans+=min*4;
    return ans;
}
int main()
{
    ll x;
    ll y;
    scanf("%llu %llu",&x,&y);
    printf("%llu",f(x,y));///unsigned long long读入
}
