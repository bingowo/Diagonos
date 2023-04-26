#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define maxn 1010

long long f[maxn];
bool primer[maxn];

bool isprimer(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
        if (0 == x % i)
            return 0;
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    f[0] = 1;
    for (int i = 3; i <= 1000; i++)
        if (isprimer(i))
            primer[i] = 1;
    primer[2] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (primer[i])
            for (int j = i; j <= n; j++)
            {
                f[j] += f[j - i];
            }
    }
    printf("%lld", f[n]);
    return 0;
}