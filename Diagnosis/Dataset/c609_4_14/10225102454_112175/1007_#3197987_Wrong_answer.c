#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define LL long long 
int min(int a, int b)
{
    return a > b ? b: a;
}

int max(int a, int b)
{
    return a < b ? b: a;
}

int calc(LL x)
{
    int res = 0;
    if (x >= 0)
    {
       while (x)
       {
           if ((x % 2) == 1)
               res++;
           x /= 2;
       }
    }
    else
    {
        x = abs(x);
        int c[64], cnt = 63;
        for (int i = 0; i <= cnt; i++)
            c[i] = 0;
        while (x)
        {
            c[cnt--] = (x % 2);
            x /= 2;
        }
        for (int i = 0; i < 64; i++)
            c[i] = 1 - c[i];
        for (int i = 63; i >= 0; i--)
            if (c[i] == 1)
                c[i] = 0;
            else
            {
                c[i] = 1;
                break;
            }
        for (int i = 0; i <= 63; i++)
            if (c[i])
                res++;
    }
    return res;
}

int cmp(const void* a, const void* b)
{
    LL A = *((LL*)a), B = *((LL*)b);
    int ca = calc(A), cb = calc(B);
    if (ca != cb)
        return cb > ca? 1: -1;
    return A > B ? 1: -1;
}

void solve(int t)
{
    printf("case #%d:\n", t);
    int n;
    scanf("%d", &n);
    LL a[10006];
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    qsort(a + 1, n, sizeof(a[1]), cmp);
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
    puts("");
    return;
}

int main(void)
{ 
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        solve(i);
    }
    return 0;
}