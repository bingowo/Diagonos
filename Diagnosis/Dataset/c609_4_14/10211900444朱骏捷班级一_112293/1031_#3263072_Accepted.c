#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void func()
{
    int a[1001] = {0};
    long long int *b = (long long int *)malloc(500501 * sizeof(long long int));
    b[0] = 0;
    int cnt = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int j = 1; j <= n; j++)
    {
        scanf("%d", &a[j]);
        a[j] += a[j - 1];
    }
    for (int len = 1; len <= n; len++)
        for (int i = 1; i <= n - len + 1; i++)
            b[++cnt] = a[i + len - 1] - a[i - 1];
    qsort(b + 1, cnt, sizeof(b[0]), cmp);
    for (int i = 1; i <= cnt; i++)
        b[i] += b[i - 1];
    for (int i = 0; i < m; i++)
    {
        int l, u;
        scanf("%d%d", &l, &u);
        printf("%lld\n", b[u] - b[l - 1]);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int z = 0; z < T; z++)
    {
        printf("case #%d:\n", z);
        func();
    }
    return 0;
}