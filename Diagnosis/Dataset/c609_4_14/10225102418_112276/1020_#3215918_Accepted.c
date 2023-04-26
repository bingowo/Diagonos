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
    int iter = 0;
    while (scanf("%s", strs[iter].s) != EOF)
    {
        int len = strlen(strs[iter].s);
        int n = 0, flag = 0;
        for (int i = 0; i < len; i++)
        {
            if (strs[iter].s[i] <= '9' && strs[iter].s[i] >= '0')
            {
                n = n * 10 + strs[iter].s[i] - 48;
                flag = 1;
            }
        }
        if (flag)
            strs[iter++].num = n;
        else
            strs[iter++].num = -1;
    }
    qsort(strs, iter, sizeof(Str), cmp);
    for (int i = 0; i < iter; i++)
        printf("%s ", strs[i].s);
    return 0;
}