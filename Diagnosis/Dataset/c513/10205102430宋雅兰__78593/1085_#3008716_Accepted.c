#include <stdio.h>
#include <string.h>

int main()
{
    char a[501], b[501];
    while (scanf("%s", a) != EOF)
    {
        scanf("%s", b);
        int al = strlen(a), bl = strlen(b);
        int at[500] = {0};
        int bt[500] = {0};
        int ans[500] = {0};
        int flag, l;
        l = (al > bl ? al : bl);
        //将两个字符数组倒序放在两个整型数组中
        for (int i = al - 1, j = 0; i >= 0; i--, j++)
            at[j] = a[i] - '0';
        for (int i = bl - 1, j = 0; i >= 0; i--, j++)
            bt[j] = b[i] - '0';

        if (al > bl)
            flag = 1;
        else if (al = bl)
            flag = strcmp(a, b);
        else
            flag = -1;

        if (flag == 0)
        {
            printf("0");
        }
        if (flag < 0)
            printf("-");
        for (int i = 0; i < l; i++)
        {
            if (flag >= 0)
            {
                if (at[i] >= bt[i])
                    ans[i] = at[i] - bt[i];
                else
                {
                    ans[i] = at[i] + 10 - bt[i];
                    at[i + 1]--;
                }
            }
            else
            {
                if (at[i] <= bt[i])
                    ans[i] = bt[i] - at[i];
                else
                {
                    ans[i] = bt[i] + 10 - at[i];
                    bt[i + 1]--;
                }
            }
        }
        int i = l, notzero = 0;
        while (i-- > 0)
        {
            if (ans[i] != 0)
                notzero = 1; //把结果前的0都处理掉，不输出，直到遇到第一个非零数再输出
            if (notzero)
                printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}