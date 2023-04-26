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
    while(max!=min&&(max!=0&&min!=0))//除法比减法效率高（当长是宽的n倍+时）
    {
        ll cnt=max/min;//存在几个最大正方形
        ans+=min*4*cnt;
        max=max-min*cnt;
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
