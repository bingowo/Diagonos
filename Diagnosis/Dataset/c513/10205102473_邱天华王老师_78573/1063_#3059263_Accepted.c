#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long

ll it_func(ll x, ll y)
{
    ll min = (x > y) ? y : x;
    ll max = (x < y) ? y : x;
    ll all = 0;
    while(max % min)
    {
        ll num = max / min;
        all += min * 4 * num;
        ll temp = min;
        min = max % min;
        max = temp;
    }

    all += max * 4;

    return all;
    

}

int main()
{
    ll x;
    ll y;
    scanf("%lld%lld",&x,&y);
    ll peri = 0;
    peri = it_func(x,y);
    printf("%lld\n",peri);
    return 0;

}
