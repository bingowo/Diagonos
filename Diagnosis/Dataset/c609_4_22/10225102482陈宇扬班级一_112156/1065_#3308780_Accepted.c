#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T; //问题数(1 <= T <= 10)
    scanf("%d\n", &T);

    char exp[105];   //保存波兰表达式
    double stk[105]; //类栈:先入后出

    for (int i = 0; i < T; i++)
    {
        gets(exp);   //读波兰表达式, 一行全读进来, 包括了空格,\n
        int top = 0; //栈的起始点
        int cnt = strlen(exp);

        for (int k = 0; k < cnt; k++)
        {
            if (exp[k] == ' ')
                exp[k] = 0;
        }

        for (int j = cnt - 1; j >= 0; j--)
        {
            double res; //记录当前的点

            if (exp[j] == '+')
            {
                res = stk[top] + stk[top - 1];
                stk[--top] = res;
            }
            else if (exp[j] == '-')
            {
                res = stk[top] - stk[top - 1];
                stk[--top] = res;
            }
            else if (exp[j] == '*')
            {
                res = stk[top] * stk[top - 1];
                stk[--top] = res;
            }
            else if (exp[j] == '/')
            {
                res = stk[top] / stk[top - 1];
                stk[--top] = res;
            }
            else if (exp[j])
            {
                while (j >= 0 && exp[j])
                    j--;
                j++;
                stk[++top] = atof(exp + j);
            }
        }

        //输出结果
        printf("case #%d:\n", i);
        printf("%.6lf\n", stk[1]);
    }

    system("pause");
    return 0;
}
