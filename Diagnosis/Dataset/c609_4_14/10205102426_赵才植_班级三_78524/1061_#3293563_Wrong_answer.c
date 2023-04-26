#include <stdio.h>
#include <string.h>

#define MAX_N 101000

int n;
int f[MAX_N];
int st[MAX_N];

int main()
{
    scanf("%d", &n);

    memset(st, 0, sizeof st);
    st[0] = st[1] = 1;
    for (int i = 2; i <= n; i ++ )
        if (!st[i])
            for (int j = i + i; j <= n; j += i)
                st[j] = 1;

    f[0] = 1;
    for (int i = 2; i <= n; i ++ )
        if (!st[i])
            for (int j = i; j <= n; j ++ )
                f[j] += f[j - i];

    printf("%d\n", f[n]);

    return 0;
}
