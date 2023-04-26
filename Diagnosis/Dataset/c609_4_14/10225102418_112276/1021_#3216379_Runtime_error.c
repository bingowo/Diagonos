#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tab[100] = {0};

typedef struct strs
{
    char str[21];
} Strs;

bool cmp(Strs s1, Strs s2)
{
    int len1 = strlen(s1.str);
    int len2 = strlen(s2.str);
    int minLen = fmin(len1, len2);
    for (int i = 0; i < minLen; i++)
    {
        if (s1.str[i] != s2.str[i])
            return tab[s1.str[i]] < tab[s2.str[i]];
    }
    return len1 < len2;
}

int main()
{
    char ch;
    int cnt = 0;
    while (scanf("%c", &ch) != EOF)
    {
        for (int i = 0; i < 52; i += 2)
        {
            tab[ch] = i;
            tab[ch + 32] = i + 1;
            scanf("%c", &ch);
        }
        Strs strs[100];
        int n = 0;
        int j = 0;
        while (ch != '\n')
        {
            strs[n].str[j++] = ch;
            ch = getchar();
            if (ch == ' ')
            {
                strs[n].str[j++] = '\0';
                ++n;
                j = 0;
                ch = getchar();
            }
        }
        strs[n].str[j++] = '\0';
        qsort(strs, n + 1, sizeof(char), cmp);
        for (int i = 0; i < i + 1; i++)
        {
            if (i != n)
                printf("%s ", strs[i].str);
            else
                printf("%s\n", strs[i].str);
        }
    }
    return 0;
}