#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
typedef long long ll;

inline int read()
{
    int ans = 0;
    char last = ' ', ch = getchar();
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        ans = ans * 10 + ch - '0', ch = getchar();
    if (last == '-')
        ans = -ans;
    return ans;
}

int n;
int prime[1000], not_prime[1050], cnt = 0;
ll f[5000];

void fun()
{
    memset(prime, 0, sizeof(prime));
    memset(not_prime, 0, sizeof(not_prime));
    not_prime[0] = not_prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!not_prime[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt; j++)
        {
            if (i * prime[j] > n)
                break;
            not_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    n = read();
    fun();
    f[0] = 1;
    for (int i = 1; i <= cnt; i++)
        for (int j = prime[i]; j <= n; j++)
            f[j] += f[j - prime[i]];
    printf("%lld", f[n]);
    return 0;
}