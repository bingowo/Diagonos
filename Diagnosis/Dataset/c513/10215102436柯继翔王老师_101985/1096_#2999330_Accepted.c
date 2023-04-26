#include <stdio.h>
#include <stdlib.h>

#define N 105

int in[N], out[N], a[N][N];

int main() {
    int t, n, x, y;
    scanf("%d", &t);
    while (t--) {
        memset(a, 0, sizeof a);
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        scanf("%d", &n);
        int ans = 1;
        for (int i = 0; i < n ; i++) {
            scanf("%d%d", &x, &y);
            if (x == y || a[x][y]) continue;
            a[x][y] = 1;
            if (out[y] || in[x] || out[x]) ans = 0;
            out[x] = in[y] = 1;
        }
        printf("%s\n",ans ? "Lucky dxw!" : "Poor dxw!");
    }
    return 0;
}
