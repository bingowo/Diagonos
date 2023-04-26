#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tab[52] = {0};

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
    while (scanf("%c", &ch) != '\n')
    {
        for (int i = 0; i < 52; i += 2)
        {
            tab[ch] = i;
            tab[ch + 32] = i + 1;
            scanf("%c", &ch);
        }

        Strs strs[100];
        int cnt = 0;
        int j = 0;
        while (ch != ' ' && ch != '\n')
        {
            strs[cnt].str[j++] = ch;
            ch = getchar();
            if (ch == ' ')
            {
                strs[cnt].str[j++] = '\0';
                cnt++;
                j = 0;
                ch = getchar();
            }
        }
        strs[cnt].str[j++] = '\0';
        qsort(strs, cnt + 1, sizeof(Strs), cmp);
        for (int i = 0; i < cnt + 1; i++)
        {
            if (i != cnt)
                printf("%s ", strs[i].str);
            else
                printf("%s\n", strs[i].str);
        }
    }
    return 0;
}