#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define ll long long 

int min(int a, int b)
{
    return a > b ? b: a;
}

int max(int a, int b)
{
    return a < b ? b: a;
}

#define N 26000
int son[N][30], idx, book[N];
int path[506];

void insert(char s[])
{
    int now = 0;
    for (int i = 1; s[i]; i++)
    {
        int x = s[i] - 'a';
        if (!son[now][x])
        {
            son[now][x] = ++idx;
        }
        now = son[now][x];
    }
    book[now] = 1;
}

void dfs(int x, int d)
{
    if (book[x])
    {
        for (int i = 1; i <= d; i++)
        {
            char ch = 'a' + path[i];
            putchar(ch);
        }
        putchar(' ');
    }
    for (int i = 0; i < 26; i++)
        if (son[x][i])
        {
            path[d + 1] = i;
            dfs(son[x][i], d + 1);
        }
}

void solve(int t)
{
    idx = 0;
    for (int i = 0; i <= N - 2; i++)
    {
        book[i] = 0;
        for (int j = 0; j <= 27; j++)
            son[i][j] = 0;
    }
    printf("case #%d:\n", t);
    int cnt = 0;
    char ch;
    char s[506];
    while ((ch = getchar()) != '\n')
    {
        if (islower(ch))
            s[++cnt] = ch;
        else
        {
            if (cnt)
            {
                s[++cnt] = '\0';
                // printf("%s\n", s + 1);
                insert(s);
                cnt = 0;
            }
        }
    }
    if (cnt)
    {
        s[++cnt] = '\0';
        insert(s);
        cnt = 0;
    }

    dfs(0, 0);
    puts("");
}

int main(void)
{ 
    int t;
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++)
        solve(i);

    return 0;
}