//暴力枚举
#include <stdio.h>

void dfs(int *f, int *w, int pos, int s, int n)
{
    if (s > 0) f[s] = 1;
    if (pos == n) return;
    dfs(f, w, pos + 1, s, n);
    dfs(f, w, pos + 1, s + w[pos], n);
    dfs(f, w, pos + 1, s - w[pos], n);
}

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    int w[n], f[1100] = {0};
    for (int i = 0; i < n; i ++){
        scanf("%d", &w[i]);
        sum += w[i];
    }
    dfs(f, w, 0, 0, n);
    for (int i = 1; i <= sum; i ++){
        printf("%d", f[i]);
    }
    return 0;
}