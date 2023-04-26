#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int x, T, i,j,k, len,maxpos,changepos,maxc;
    char s[100], * p, c;
    scanf("%d", &T);
    for (x = 0;x < T;x++)
    {
        printf("case #%d:\n", x);
        memset(s, 0, sizeof(s));
        s[0] = '0';
        scanf("%s", s + 1);
        p = s + 1;
        len = strlen(p);
        for (i = len-1;i>-1;i--)
        {
            if (i != 0)
            {
                for (j = i - 1;j > -1;j--)
                {
                    if (p[i] > p[j])
                    {
                        c = p[i];
                        p[i] = p[j];
                        p[j] = c;
                        changepos = j;
                        i = -1;               //为了退出外层for
                        break;
                    }
                }
            }
            else
            {
                for (j = len - 1;j > -1;j--)
                {
                    if (p[j] > '0')
                    {
                        s[0] = p[j];
                        p[j] = '0';
                        changepos = 0;
                        break;
                    }
                }
                p--;
                len++; 
            }
        }
        for (i = len - 1;i > changepos;i--)
        {
            maxpos = len - 1;
            maxc = p[len - 1];
            if (p[i] >= maxc)
            {
                maxpos = i;
                maxc = p[i];
            }
        }
        p[maxpos] = p[len - 1];
        p[len - 1] = maxc;
        printf("%s", p);
    }
    return 0;
}