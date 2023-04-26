#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n, i, j, len;
    char dict[4001][15], * s;
    s = (char*)malloc(5001 * sizeof(char));
    scanf("%d", &n);
    for (i = 0;i < n;i++)
    {
        scanf("%s", dict[i]);
    }
    scanf("%s", s);
    while (strlen(s) > 0)
    {
        len = strlen(s);
        for (j = len;j > 0;j--)
        {
            if (j == 1)
            {
                printf("%c ", s[0]);
                s += 1;
            }
            else
            {
                for (i = 0;i < n;i++)
                {
                    if (j == strlen(dict[i]) && strncmp(s, dict[i], j)==0)
                    {
                        printf("%s ", dict[i]);
                        s += j;
                    }
                }
            }

        }
    }

    //func(s,strlen(s));
    return 0;
}
