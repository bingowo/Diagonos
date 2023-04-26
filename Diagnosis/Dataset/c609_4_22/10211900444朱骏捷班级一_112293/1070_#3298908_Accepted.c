#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define ull unsigned long long

ull a[100], cnt = 0;
int n;

ull int_pow(int base, int index)
{
    ull res = 1;
    for (int i = 0; i != index; i++)
    {
        res *= 2;
    }
    return res;
}

void dfs(int cur)
{
    if (cur >= n)
    {
        return;
    }
    if (a[cur] == 1 && a[cur - 1] == 0 && a[cur - 2] == 1)
    {
        cnt += int_pow(2, n - cur - 1);
        return;
    }
    a[cur + 1] = 0;
    dfs(cur + 1);
    a[cur + 1] = 1;
    dfs(cur + 1);
}

int main()
{
    scanf("%d", &n);
    while (n != -1)
    {
        dfs(-1);
        printf("%llu\n", int_pow(2, n) - cnt);
        scanf("%d", &n);
        cnt = 0;
    }
    return 0;
}