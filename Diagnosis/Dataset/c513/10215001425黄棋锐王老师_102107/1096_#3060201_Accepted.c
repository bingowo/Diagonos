#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 
公平：命令打乱后，相同初始牌的结尾牌肯定一样
 
如何通过命令序列判定公平性：
1，命令序列不能够出现首尾相连的情况
即 x-y，y-z同时出现时不公平，因为一旦更换命令顺序（如y-z，x-y），x就会得到不同编号的卡牌。
2，命令序列不能出现终点不一致的情况
即x-y，x-z出现时出现不公平；

处理特殊命令：
1，x-x的命令需要忽略；
2，x-y重复出现时需要忽略；
*/ 

const int N = 105;
int main() {
	int in[N], out[N], a[N][N];
	/*in[N]：存储命令的终点，存在x-y的命令时，in[y]为1
out[N]：存储命令的起点，存在x-y的命令时，out[x]为1
 a[N][N]：存储命令是否出现，存在x-y的命令时， a[x][y] =1
 	*/ 

    int t, n, x, y;
    scanf("%d", &t);
    while (t--) {
        memset(a, 0, sizeof a); //初始化数组a
        memset(in, 0, sizeof in);//初始化数组in
        memset(out, 0, sizeof out);//初始化数组out
        scanf("%d", &n);
        int ans = 1,i;
        for (i = 0; i < n ; i++) {
            scanf("%d%d", &x, &y);//读入命令x-y
            //命令是x-x型，或者曾经出现过，忽略
            if (x == y || a[x][y]) continue; 
            a[x][y] = 1; // 记录x-y命令 
            if (out[y] || in[x] || out[x]) ans = 0;//一旦出现首尾相接和x-z的情况 
            out[x] = in[y] = 1;
        }
        puts(ans ? "Lucky dxw!" : "Poor dxw!");
    }
    return 0;
}
