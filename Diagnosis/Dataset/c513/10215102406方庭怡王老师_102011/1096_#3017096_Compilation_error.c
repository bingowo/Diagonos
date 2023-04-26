#include <stdio.h>
#include <string.h>
const int N = 105;

int in[N], out[N], a[N][N];

int main() {
    int t, n, x, y;
    scanf("%d", &t);
    while (t--) {
        memset(a, 0, sizeof a); //初始化数组a
        memset(in, 0, sizeof in);//初始化数组in
        memset(out, 0, sizeof out);//初始化数组out
        scanf("%d", &n);
        int ans = 1;
        for (int i = 0; i < n ; i++) {
            scanf("%d%d", &x, &y);//读入命令
            //命令是x-x型，或者曾经出现过，忽略
            if (x == y || a[x][y]) continue; 
            a[x][y] = 1; 
            if (out[y] || in[x] || out[x]) ans = 0;
            out[x] = in[y] = 1;
        }
        puts(ans ? "Lucky dxw!" : "Poor dxw!");
    }
    return 0;
}