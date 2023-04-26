#include <stdio.h>

int countno101(int n);

int main()
{
    int n, ans;

    scanf("%d", &n);
    while ( n != -1){
        ans = countno101(n);
        printf("%d\n",ans);
        scanf("%d", &n);
    }
    return 0;
}

int countno101(int n)
{
    int f[21], g[21];
    f[0] = g[0] = 0;
    f[1] = g[1] = 1;

    for (int i = 2; i <= 20; i++){
        f[i] = f[i-1] + g[i-1];
        g[i] = f[i] - g[i-2];
    }

    return f[n] + g[n];
}
