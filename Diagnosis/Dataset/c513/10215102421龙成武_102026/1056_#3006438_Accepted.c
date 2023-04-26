#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compar(const void* p1, const void* p2)
{
    char(*a)[15], (*b)[15];
    a = (char(*)[15])p1;
    b = (char(*)[15])p2;
    return strlen(*a) - strlen(*b);         //二维数组排序的初尝试
}
int main()
{
    int n, i, j, len, flag, dictlen[16];
    char dict[4001][15], * s;
    s = (char*)malloc(5001 * sizeof(char));
    scanf("%d", &n);
    for (i = 0;i < n;i++)
    {
        scanf("%s", dict[i]);
    }
    qsort(dict, n, 15 * sizeof(char), compar);
    for (i = 0;i < 16;i++)
    {
        dictlen[i] = n;  //降低时间复杂度或许没那么难，用个字典索引记录长度就很有用
    }
    i = 1;j = 0;
    while (j < n&& i < 16)
    {
        len = strlen(dict[j]);
        if (dictlen[len] == n)
        {
            dictlen[len] = j;
        }
        j++;
    }
    scanf("%s", s);
    while (strlen(s) > 0)
    {
        flag = 0;
        len = strlen(s);
        for (j = len;j > 0;j--)
        {
            if (j > 14)
                j = 14;
            if (j == 1)
            {
                printf("%c ", s[0]);
                s += 1;
                flag = 1;
            }
            else
            {
                int p1, p2;
                p1 = dictlen[j];            //长度为j的单词在dict里的起始下标
                p2 = dictlen[j + 1];        //长度为j+1的单词的起始下标
                for (i = p1;i < p2;i++)
                {
                    if (strncmp(s, dict[i], j) == 0)
                    {
                        printf("%s ", dict[i]);
                        s += j;
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
                break;
        }
    }

    //func(s,strlen(s));
    return 0;
}
