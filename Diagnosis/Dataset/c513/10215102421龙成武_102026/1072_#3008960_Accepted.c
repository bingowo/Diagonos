#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef long long ll;
int dp[32][32];
void func(ll x, ll y, ll step)
{
    if (step == 0)
        return;
    else
    {
        if (llabs(x) > llabs(y))
        {
            if (x > 0)
            {
                func(x - pow(2, step - 1), y, step - 1);
                printf("E");
            }
            else
            {
                func(x + pow(2, step - 1), y, step - 1);
                printf("W");
            }
        }
        else
        {
            if (y > 0)
            {
                func(x, y - pow(2, step - 1), step - 1);
                printf("N");
            }
            else
            {
                func(x, y + pow(2, step - 1), step - 1);
                printf("S");
            }
        }
    }
}
int main()
{
    int i;
    ll x, y, temp, steplen, step;
    scanf("%lld %lld", &x, &y);
    steplen = llabs(x) + llabs(y);
    if (x == 0 && y == 0)
        printf("0");
    else if (steplen % 2 == 0)
        printf("-1");
    else
    {
        temp = 2;
        for (i = 1;i < 64;i++)
        {
            if (temp - 1 >= steplen)
                break;
            else
                temp *= 2;
        }
        printf("%d\n", i);
        func(x, y, i);
    }
    return 0;
}