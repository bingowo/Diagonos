#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int order1[101], order2[101][101];
int main()
{
    int T, n, i,j, a, b, flag = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        memset(order1, 0, sizeof(order1));memset(order2, 0, sizeof(order2));
        flag = 1;
        for (i = 0;i < n;i++)
        {
            scanf("%d %d", &a, &b);
            if (order1[a] == 0) order1[a] = 1;
            else
            {
                for (j = 0;j < 101;j++)
                {
                    if (j == b);
                    else if (order2[a][j] == 1) 
                    {
                        flag = 0;break;
                    }
                }
                for (j = 0;j < 101;j++)
                {
                    if (order2[j][a] == 1)
                    {
                        flag = 0;break;
                    }
                }
            }
            if (order1[b] == 0) order1[b] = 1;
            else
            {
                for (j = 0;j < 101;j++)
                {
                    if (j == a);
                    else if (order2[j][b] == 1) 
                    {
                        flag = 0;break;
                    }
                }
                for (j = 0;j < 101;j++)
                {
                    if (order2[b][j] == 1)
                    {
                        flag = 0;break;
                    }
                }
            }
            order2[a][b] = 1;
        }
        if (flag) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}
