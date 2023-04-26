#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int order2[101][101];
int main()
{
    int T, n, i,j, a, b, choice,flag = 1, A[101], B[101];
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
        for (i = 0;i < n;i++)
        {
            choice = 0;
            a = A[i];
            b = B[i];
            if (flag)
            {
                for (j = 0;j < 101;j++)
                {
                    if (order2[a][j] == 1) choice++;
                    if (choice > 1)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (choice == 1)
                {
                    for (j = 0;j < 101;j++)
                    {
                        if (order2[b][j] == 1 && j != a)
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
        }
        if (flag) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}
