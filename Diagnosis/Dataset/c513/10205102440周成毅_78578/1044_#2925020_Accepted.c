#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100000

unsigned shu[MAXN];

char s[MAXN];

unsigned zhuan(char *s, int len)
{
    unsigned sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            sum = sum * 16 + s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            sum = sum * 16 + s[i] - 'a' + 10;
    }
    return sum;
}

int hefa(char c)
{
    if ((c >= '0' && c<= '9') || (c <= 'f' && c >= 'a'))
        return 1;
    return 0;
}

int main()
{
    scanf("%s\n", s);
    int shul = -1;
    int len = strlen(s);
    for (int i = 2; i < len; i++)
    {
        if (s[i-2] == '0' && s[i-1] == 'x' && hefa(s[i]))
        {
            int l = 0;
            shu[++shul] = 0;
            while (hefa(s[i+l]))
            {
                if (s[i+l] >= '0' && s[i+l] <= '9')
                    shu[shul] = shu[shul] * 16 + s[i+l] - '0';
                else if (s[i+l] >= 'a' && s[i+l] <= 'f')
                    shu[shul] = shu[shul] * 16 + s[i+l] - 'a' + 10;
                l++;
            }
        }
    }
    if (shul == -1)
        printf("%d\n", shul);
    else
    {
        for (int i = 0; i <=  shul; i++)
            printf("%u ", shu[i]);
        printf("\n");
    }
    return 0;
}