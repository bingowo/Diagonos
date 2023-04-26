#include<stdio.h>
typedef long long ll;
ll f(ll n)//求n数码的9进制结果
{
    int a[20],cnt=0,i;ll result=0;
    while(n)
    {
        a[cnt++]=n%10;
        n/=10;
    }
    for(i=cnt-1;i>-1;--i)result=result*9+a[i];
    return result;
}
ll g(ll n)//求n数码的最后一组的9的倍数的个数
{
    ll tmp=n-n%10,i,cnt=0;
    for(i=tmp+1;i<=n;i++)if(!(i%9))cnt++;
    return cnt;
}
int main()
{
    ll a,b;scanf("%lld %lld",&a,&b);
    printf("%lld",f(b)-f(b-b%10)/9-g(b)-f(a)+f(a-a%10)/9+g(a)+1);
    return 0;
}