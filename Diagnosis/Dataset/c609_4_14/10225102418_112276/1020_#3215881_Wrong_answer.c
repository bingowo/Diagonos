#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str
{
    char s[31];
    int num;
} Str;

int cmp(const void *str1, const void *str2)
{
    Str temp1 = *(Str *)str1;
    Str temp2 = *(Str *)str2;
    if (temp1.num == temp2.num)
        return strcmp(temp1.s, temp2.s);
    else
        return temp1.num - temp2.num;
}

int main()
{
    Str strs[101];
    for (int i = 0; i < 101; ++i)
        strs[i].num = -1;
    int k = 0;
    while (scanf("%s", strs[k].s) != EOF)
    {
        int len = strlen(strs[k].s);
        int n = 0, flag = 0;
        for (int i = 0; i < len; i++)
        {
            if (strs[k].s[i] <= '9' && strs[k].s[i] >= '0')
            {
                n = n * 10 + strs[k].s[i] - 48;
                flag = 1;
            }
        }
        if (flag)
            strs[k++].num = n;
    }
    qsort(strs, k, sizeof(Str), cmp);
    for (int i = 0; i < k; i++)
        printf("%s ", strs[i].s);
    return 0;
}