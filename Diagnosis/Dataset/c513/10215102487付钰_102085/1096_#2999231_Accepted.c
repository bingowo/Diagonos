#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 105
int yu[N];
int out[N];
int a[N][N];
int main() {
int t, n, x, y;
scanf("%d", &t);
while (t--) {
memset(a, 0, sizeof a); //初始化数组a
memset(yu, 0, sizeof yu);//初始化数组in
memset(out, 0, sizeof out);//初始化数组out
scanf("%d", &n);
int ans = 1;
for (int i = 0; i < n ; i++) {
scanf("%d%d", &x, &y);//读入命令
//命令是x-x型，或者曾经出现过，忽略
if (x == y || a[x][y]) continue;
a[x][y] = 1;
if (out[y] || yu[x] || out[x]) ans = 0;
out[x] = yu[y] = 1;
}
puts(ans ? "Lucky dxw!" : "Poor dxw!");
}
return 0;
}
