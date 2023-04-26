#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
int main()
{
    int i, j, k, temp;
    int T, n;
    double fps[26] = { 0 }, t;
    double s[M] = { 0 };
    char ss[M] = { 0 };
    char c;
    char ts;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        n = 0;
        for (j = 0; j < 26; j++)
        {
            scanf("%lf", &fps[j]);
        }
        c = getchar();
        while ((c = getchar()) != '\n')
        {
            ss[n] = c;
            if (('a' <= c) && (c <= 'z'))
            {
                temp = c - 'a';
            }
            else if(('A'<=c)&&(c<='Z'))
            {
                temp = c - 'A';
            }
            s[n] = fps[temp];
            n++;
        }
        for (j = 0; j < n - 1; j++)
        {
            for (k = 0; k < n - 1 - j; k++)
            {
                if (s[k] < s[k + 1])
                {
                    t = s[k]; s[k] = s[k + 1]; s[k + 1] = t;
                    ts = ss[k]; ss[k] = ss[k + 1]; ss[k + 1] = ts;
                }
                else if (s[k] == s[k + 1])
                {
                    if ((ss[k] - 'A') < (ss[k + 1] - 'A'))
                    {
                        t = s[k]; s[k] = s[k + 1]; s[k + 1] = t;
                        ts = ss[k]; ss[k] = ss[k + 1]; ss[k + 1] = ts;
                    }
                }
            }
        }
        printf("case #%d:\n", i);
        for (j = 0; j < n; j++)
        {
            printf("%c", ss[j]);
            s[j] = 0;
            ss[j] = 0;
        }
        printf("\n");
    }
    return 0;

}