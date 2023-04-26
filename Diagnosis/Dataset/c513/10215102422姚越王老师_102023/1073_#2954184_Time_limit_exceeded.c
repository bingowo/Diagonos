#include<stdio.h>
typedef long long ll;
int judge(ll n)
{
    if(!(n%9))return 0;
    while(n)
    {
        if(n%10==9)return 0;
        n/=10;
    }
    return 1;
}
int main()
{
    ll cnt=0,a,b;scanf("%lld %lld",&a,&b);
    while(a<=b)
    {
        if(judge(a))cnt++;
        a++;
    }
    printf("%lld",cnt);
    return 0;
}