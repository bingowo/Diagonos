#include <stdio.h>
#include <string.h>

const int MAXN = 100;  // 数组的最大长度
int f[MAXN][MAXN];      // 存储斐波那契数列的数组，每个元素存储1个整数的1位

void mul(int f[], int len, int x)
{
    int c = 0;
    for (int i = 0; i < len; i++)
    {
        int t = f[i] * x + c;
        f[i] = t % 10;
        c = t / 10;
    }
    while (c > 0)
    {
        f[len++] = c % 10;
        c /= 10;
    }
}

void solve(int n)
{
 // 初始化斐波那契数列的前2项
    memset(f, 0, sizeof(f));
    f[1][0] = 1;

    // 计算斐波那契数列的每一项
    for (int i = 2; i <= n; i++)
    {
        memcpy(f[i], f[i-1], sizeof(f[i]));   // 复制上一项的值
        mul(f[i], i, 2);                       // 将上一项的值乘以2
        mul(f[i-2], i, 1);                     // 将上上一项的值乘以1
    }

    // 输出斐波那契数列第n项的值
    int len = n;
    while (f[n][len-1] == 0) len--;   // 去除前导0
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        solve(n);
        printf("case #%d:\n",i);
        for (int i = len-1; i >= 0; i--)
        {
            printf("%d",f[n][i]);
        }
        printf("\n");
    }
    return 0;
}