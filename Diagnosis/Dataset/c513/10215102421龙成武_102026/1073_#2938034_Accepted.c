#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long

int a[20];
ll f[20][10];
ll dp(int pos, int sum, int flag)
{
    int x;
    ll res = 0;
    if (pos == 0)
    {
        if(sum%9==0)
            return 0;
        else return 1;
    }
        //return (sum % 9 == 0);      //如果sum和mod都是9的倍数，返回1，让res加一；
    else if (flag && f[pos][sum] != -1)
        return f[pos][sum];

    if (flag == 0)
        x = a[pos];
    else
        x = 9;

    for (int i = 0;i <= x;i++)
    {
        if(i!=9)
            res += dp(pos - 1, (sum * 10 + i) % 9,  flag || i < x);
    }
    if (flag!=0)
        f[pos][sum] = res;
    return res;
}
ll cal(ll x)
{
    int pos = 0;
    while (x)
    {
        a[++pos] = x % 10;      //pos代表x的位数，呃，十进制位数
        x /= 10;
    }
    ll res = dp(pos, 0, 0);      //dp是一个函数，你传进去x的十进制最高位(pos),sum,mod,flag值，就可以求出符合题意的数字个数
    return res;
}
int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    memset(f, -1, sizeof(f));
    printf("%lld", (cal(m) - cal(n-1)));
}
