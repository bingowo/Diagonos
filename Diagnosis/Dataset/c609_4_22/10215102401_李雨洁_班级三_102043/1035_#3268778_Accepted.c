#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[105] = { 1 };
void remov(char* str)//消除相邻字符，将结果保存在原来字符串中
{
    for (int i = 0; i < 105; ++i)   stack[i] = 0;//清空辅助栈
    int len = strlen(str);
    int e = 0;
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            if (str[i] == str[i + 1]);
            else stack[e++] = str[i];
        }
        else if (i == len - 1)
        {
            if (str[i] == str[i - 1]);
            else stack[e++] = str[i];
        }
        else
        {
            if (str[i] == str[i + 1] || str[i] == str[i - 1]);
            else stack[e++] = str[i];
        }
    }
    int llen = strlen(stack);
    if (len == llen)
    {
        stack[0] = 0;
        return;
    }
    else
    {
        int i = 0;
        for (i = 0; i < llen; ++i)  str[i] = stack[i];
        str[i] = 0;
        stack[0] = 1;
    }
    return;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++)
    {
        int end = 0;
        stack[0] = 1;
        char s[105] = { 0 };
        scanf("%s", s);
        int len = strlen(s) + 1;
        char str[105] = { 0 };
        for (int i = 0; i <= len; i++)
        {
            for (char c = 'A'; c < 'D'; c++)
            {
                int j = 0;
                for (j = 0; j <= len; j++)
                {
                    if (j < i)   str[j] = s[j];
                    else if (i == j)   str[j] = c;
                    else  str[j] = s[j - 1];
                }
                str[j] = 0;
                while (stack[0] != 0) 
                    remov(str); 
                stack[0] = 1;
                int llen = strlen(str);
                end = end > len - llen ? end : len - llen;
            }
        }
        printf("case #%d:\n", z);
        printf("%d\n", end);
    }
    return 0;
}