#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int min(int a, int b)
{
    return a > b ? b: a;
}

int max(int a, int b)
{
    return a < b ? b: a;
}


#define N 10000006
char s[N];
int main(void)
{ 
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != EOF)
        s[++cnt] = ch;

    int flag = 1;
    for (int i = 1; i <= cnt; i++)
    {
        if (s[i] == '\"')
            flag = 1 - flag;
        if (flag && s[i] == '/' && s[i + 1] == '*')
        {
            int j = i + 2;
            while (s[j] != '*' || s[j + 1] != '/')
                j++;
            j++;
            i = j;
        }
        else if (flag && s[i] == '/' && s[i + 1] == '/')
        {
            int j = i + 2;
            while (s[j] != '\n')
                j++;
            i = j - 1;
        }
        else
            putchar(s[i]);
    }
    return 0;
}