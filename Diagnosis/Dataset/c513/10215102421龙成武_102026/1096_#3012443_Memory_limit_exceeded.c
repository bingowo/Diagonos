#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int order1[101], order2[101][101];
int theend(int a, int b)
{
    int i, j, end=b;
    for (i = 0; i < 101;i++)
    {
        if (order2[b][i] == 1)
        {
            end = theend(b, i);
            if (end == a || end == b) continue;     //跳过这个路径，去下一个路径
            else if (!(end == a || end == b)) break;
        }
    }
    return end;
}
int main()
{
    int T, n, i, ans, a, b, flag = 1, A[101], B[101];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        memset(order1, 0, sizeof(order1));memset(order2, 0, sizeof(order2));
        memset(A, 0, sizeof(A));memset(B, 0, sizeof(B));
        flag = 1;
        for (i = 0;i < n;i++)
        {
            scanf("%d %d", &A[i], &B[i]);
            order2[A[i]][B[i]] = 1;
        }
        for (i = 0;i < n;i++)
        {
            a = A[i];
            b = B[i];
            if (flag)
            {
                order2[a][b] = 1;
                if (!(theend(a, b) == a || theend(a, b) == b))
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}
