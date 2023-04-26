#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define N 1010

int text(char *s)
{
    int i = 0;
    int len = strlen(s);
    while (i < len - 1)
    {
        if (s[i] == s[i + 1])
            return 1;
        i++;
    }
    return 0;
}

int f(char *s)
{
    int i = 0;
    char x[N];
    int len = strlen(s);
    while (i < len)
    { // ABCCBCCAA
        if (s[i] == s[i + 1] && i + 1 < len)
        {
            int j = i;
            while (s[j] == s[j + 1] && j < len - 1)
            {
                j++;
            }
            i = j + 1;
        }
        else
        {
            char c[2] = {(char)s[i], '\0'};
            strcat(x, c);
            i++;
        }
    }
    if (text(x) && x[0] != '\0')
        return f(x);
    else
        return strlen(x);
}

void insert(char *s, int pos, int flag)
{
    int len = strlen(s);
    for (int i = len + 1; i > pos; i--)
        s[i] = s[i - 1];
    if (flag == 1)
        s[pos] = 'A';
    else if (flag == 2)
        s[pos] = 'B';
    else
        s[pos] = 'C';
}

int min(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}

int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++)
    {
        char s[N];
        scanf("%s", s);
        int sum = 0, len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            char x[N], y[N], z[N];
            strcpy(x, s);
            strcpy(y, s);
            strcpy(z, s);
            insert(x, i, 1);
            insert(y, i, 2);
            insert(z, i, 3);
            int a = f(x);
            int b = f(y);
            int c = f(z);
            int Min = min(min(a, b), c);
            Min = len + 1 - Min;
            sum = max(sum, Min);
        }
        printf("case #%d:\n%d\n", k, sum);
    }
    return 0;
}