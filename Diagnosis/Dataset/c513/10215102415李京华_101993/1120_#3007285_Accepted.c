#include <stdio.h>

void solve() {
    int r, c, n, k;
    scanf("%d%d%d%d", &r, &c, &n, &k);
    int matrix[r+1][c+1];
    for (int i = 0; i <= r; ++i)
        for (int j = 0; j <= c; ++j)
            matrix[i][j] = 0;

    int x, y;
    for (int i = 0; i < n; ++i){
        scanf("%d%d", &x, &y);
        for (int p = x; p <= r; ++p)
            for (int q = y; q <= c; ++q)
                ++matrix[p][q];
    }

    int ans = 0;
    for (int x1 = 1; x1 <= r; ++x1)
        for (int y1 = 1; y1 <= c; ++y1)
            for (int x2 = x1; x2 <= r; ++x2)
                for (int y2 = y1; y2 <= c; ++y2)
                    if (matrix[x2][y2] - matrix[x2][y1-1] - matrix[x1-1][y2] + matrix[x1-1][y1-1] >= k)
                        ++ans;

    printf("%d\n", ans);
}

int main() {
    int t, k = 0;
    scanf("%d", &t);
    while(t--) {
        printf("case #%d:\n", k++);
        solve();
    }
    return 0;
}