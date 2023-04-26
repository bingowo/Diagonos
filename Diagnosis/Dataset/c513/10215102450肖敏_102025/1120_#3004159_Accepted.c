#include <stdio.h>
#include <string.h>

int a[11][11];
int s[1001][1001];

int main() {
    int T;
    scanf("%d", &T);
    int r, c, n, k;
    for (int e = 0; e < T; e++) {
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        scanf("%d%d%d%d", &r, &c, &n, &k);

        for (int j = 0; j < n; j++) {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x][y] = 1;
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++)
                s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
        }

        int ans = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                for (int x = i; x <= r; x++) {
                    for (int y = j; y <= c; y++) {
                        if (s[x][y] - s[i - 1][y] - s[x][j - 1] + s[i - 1][j - 1] >= k)
                            ans++;
                    }
                }
            }
        }
        printf("case #%d:\n%d\n", e, ans);
    }
    return 0;
}
