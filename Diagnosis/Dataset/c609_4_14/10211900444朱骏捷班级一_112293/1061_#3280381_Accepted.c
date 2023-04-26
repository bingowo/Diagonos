#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxn 1010
int n, cnt, p[maxn];
unsigned long long f[maxn];
bool np[maxn];

void init()
{
    for (int i = 2; i <= n; i++)
    {
        if (!np[i])
        {
            p[cnt++] = i;
            for (int j = i; j <= n / i; j++)
                np[i * j] = true;
        }
    }
}

void comp_pack(int c)
{
    for (int i = c; i <= n; i++)
        f[i] += f[i - c];
}

int main()
{
    scanf("%d", &n);
    init();
    f[0] = 1;
    for (int i = 0; i < cnt && p[i] <= n; i++)
        comp_pack(p[i]);
    printf("%llu", f[n]);
    return 0;
}