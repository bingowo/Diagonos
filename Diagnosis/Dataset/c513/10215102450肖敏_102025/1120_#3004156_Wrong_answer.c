#include <stdio.h>
#include <string.h>

int a[11][11];
int s[1001][1001];

int main() {
    int T;
    scanf("%d", &T);
    int r, c, n, k;
    for (int i = 0; i < T; i++) {
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        scanf("%d%d%d%d", &r, &c, &n, &k);

        for (int j = 0; j < n; j++) {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x][y] = 1;
        }
        for (int j = 1; j <= r; j++) {
            for (int z = 1; z <= c; z++)
                s[j][z] = s[j][z - 1] + s[j - 1][z] - s[j - 1][z - 1] + a[j][z];
        }

        long long ans = 0;
        for (int j = 1; j <= r; j++) {
            for (int x = 1; x <= c; x++) {
                for (int y = 1; y <= r; y++) {
                    for (int z = 1; z <= c; z++) {
                        if (s[y][z] - s[j - 1][z] - s[y][x - 1] + s[j - 1][x - 1] >= k)
                            ans++;
                    }
                }
            }
        }
        printf("case #%d:\n%lld\n", i, ans);
    }
    return 0;
}
