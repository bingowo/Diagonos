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

void solve(void)
{
    char s[106], stk[106];
    int top = 0;
    scanf("%s", s + 1);
    for (int i = 1; s[i]; i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            if (top && stk[top] != '[')
            {
                puts("No");
                return;
            }
            stk[++top] = ch;
        }
        else if (ch == '[')
        {
            if (top && stk[top] != '{')
            {
                puts("No");
                return;
            }
            stk[++top] = ch;
        }
        else if (ch == '{')
        {
            if (top && stk[top] != '(')
            {
                puts("No");
                return;
            }
            stk[++top] = ch;
        }
        else if (ch == ']')
        {
            if (!top || stk[top] != '[')
            {
                puts("No");
                return;
            }
            top--;
        }
        else if (ch == '}')
        {
            if (!top || stk[top] != '{')
            {
                puts("No");
                return;
            }
            top--;
        }
        else if (ch == ')')
        {
            if (!top || stk[top] != '(')
            {
                puts("No");
                return;
            }
            top--;
        }
    }
    if (top)
        puts("No");
    else
        puts("Yes");
    return;
}

int main(void)
{ 
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}