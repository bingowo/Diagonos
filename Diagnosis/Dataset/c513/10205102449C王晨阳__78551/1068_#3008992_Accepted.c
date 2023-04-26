#include <stdio.h>
#define MAXN 33

unsigned f[MAXN];

int main()
{
    int m, n;
    m = n = 0;
    scanf("%d %d\n", &n, &m);
    while (!(m == -1 && n == -1))
    {
        for (int i = 0; i < m; i++)
            f[i] = 0;
        f[m] = 1;
        unsigned j = 1;
        for (int i = m+1; i <= n; i++)
        {
            f[i] = 2 * f[i-1] + j - f[i-m-1];
            j *= 2;
        }
        printf("%d\n", f[n]);
        scanf("%d %d\n", &n, &m);
    }
    return 0;
}