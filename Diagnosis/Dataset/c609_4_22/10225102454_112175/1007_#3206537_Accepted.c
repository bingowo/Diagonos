#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define LL long long
#define ULL unsigned long long
int min(int a, int b)
{
    return a > b ? b: a;
}

int max(int a, int b)
{
    return a < b ? b: a;
}

LL calc(LL x)
{
    LL res = 0;
    if (x >= 0)
    {
       while (x)
       {
           if (x & 1)
               res++;
           x >>= 1;
       }
    }
    else
    {
        ULL xx = (ULL)x; 
        while (xx)
        {
            if (xx & 1)
                res++;
            xx >>= 1;
        }
    }
    return res;
}

int cmp(const void* a, const void* b)
{
    LL A = *((LL*)a), B = *((LL*)b);
    LL ca = calc(A), cb = calc(B);
    if (ca != cb)
        return cb > ca? 1: -1;
    return A > B ? 1: -1;
}

void solve(int t)
{
    printf("case #%d:\n", t);
    int n;
    scanf("%d", &n);
    LL a[20006];
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