#include<stdio.h>
#include<math.h>
typedef unsigned long long ll;
ll f(ll x,ll y)
{
    if(x==y) return x*4;
    if(x>y) return f(x-y,y)+y*4;
    else return f(x,y-x)+x*4;
}
int main()
{
    ll x;
    ll y;
    scanf("%llu %llu",&x,&y);
    printf("%llu",f(x,y));///unsigned long long读入
}
