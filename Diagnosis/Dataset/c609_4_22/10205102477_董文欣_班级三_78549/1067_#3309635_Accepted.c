#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, n, m, x;
    scanf("%d %d %d %d", &a, &n, &m, &x);
    int up[21], down[21]; //上下车人数
    int sum[21]; //车上总人数
    up[1] = a; down[1] = 0; sum[1] = a;
    int t; //在第二站上车/下车的人数
    for (t = 0; t <= m; t++) {
        up[2] = t; down[2] = t; sum[2] = a;
        for (int i = 3; i <= n; i++) {
            up[i] = up[i-1] + up[i-2];
            down[i] = up[i-1];
            sum[i] = sum[i-1] + up[i] - down[i];
        }
        if (sum[n-1] == m) {
            printf("%d\n", sum[x]);
            break;
        }
    }

    return 0;
}
