#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int order2[101][101];
int main()
{
    int T, n, i,j, a, b, in,out,flag = 1, A[101], B[101];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        memset(order2, 0, sizeof(order2));
        memset(A, 0, sizeof(A));memset(B, 0, sizeof(B));
        flag = 1;
        for (i = 0;i < n;i++)
        {
            scanf("%d %d", &A[i], &B[i]);
            order2[A[i]][B[i]] = 1;
        }
        for (i = 0;i < n&&flag;i++)
        {
            in = out = 0;
            a = A[i];b = B[i];
            for (j = 0;j < 101;j++)
            {
                if (order2[a][j] == 1) out++;
            }
            for (j = 0;j < 101;j++)
            {
                if (order2[j][a] == 1) in++;
            }
            //代码、实现都不是关键，关键是游戏规则，看懂规则后，做到其实很简单
            if (out >= 2 || (in >= 1 && out >= 1))
                flag = 0;
        }
        if (flag) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}
