#include <stdio.h>
int main()
{
    int u[21] = {0, 1, 0};
    for (int i = 3; i < 22; i++)
        u[i] = u[i - 1] + u[i - 2];

    int v[21] = {0, 0, 1};
    for (int i = 3; i < 22; i++)
        v[i] = v[i - 1] + v[i - 2];

    int su[21] = {0, 1, 1};
    for (int i = 3; i < 22; i++)
        su[i] = su[i - 1] + v[i - 1] - v[i - 2];
    int sv[21] = {0, 0, 0};
    for (int i = 3; i < 22; i++)
        sv[i] = sv[i - 1] + v[i] - v[i - 1];
    int a, n, m, x;
    scanf("%d%d%d%d", &a, &n, &m, &x);
    int t = (m - su[n - 1] * a) / sv[n - 1];
    int res = su[x] * a + sv[x] * t;
    printf("%d", res);
}
