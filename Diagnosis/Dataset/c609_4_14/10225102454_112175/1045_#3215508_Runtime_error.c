#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
int min(int a, int b){ return a > b ? b: a; }
int max(int a, int b){ return a < b ? b: a; }


#define N 10000006
char s[N];
char stk[N];
int top = 0;

int main(void)
{ 
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != EOF)
        s[++cnt] = ch;

    for (int i = 1; i <= cnt; i++)
    {
        if (s[i] == '\"' && (i == 1 || s[i - 1] != '\\'))
        {
            int j = i + 1;
            putchar(s[i]);
            while (s[j] != '\"' || s[j - 1] == '\\')
                putchar(s[j]), j++;
            putchar(s[j]);
            i = j;           
        }
        else if (s[i] == '\''&& (i == 1 || s[i - 1] != '\\'))
        {
            int j = i + 1;
            putchar(s[i]);
            while (s[j] != '\'' || s[j - 1] == '\\')
                putchar(s[j]), j++;
            putchar(s[j]);
            i = j;         
        }
        else if (s[i] == '/' && s[i + 1] == '*')
        {
            int j = i + 2;
            while (s[j] != '*' || s[j + 1] != '/')
                j++;
            i = j + 1;
        }
        else if (s[i] == '/' && s[i + 1] == '/')
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