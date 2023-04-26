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

#define N 106
int n, a[N], b[N];
char s[N];

int calc(int p, int x)
{
    int nn = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == p)
            b[++nn] = x;
        b[++nn] = a[i];
    }
    if (p == n + 1)
        b[++nn] = x;

    // for (int i = 1; i <= nn; i++)
    //     printf("%d ", b[i]);
    // puts("");
    int flag = 1;
    int cnt = 0, stk[N];
    for (int i = 1; i <= nn; i++)
        stk[++cnt] = b[i];
    while (flag)
    {
        int top = 0;
        flag = 0;
        for (int i = 1; i <= cnt; i++)
        {
            if (i <= cnt - 1 && stk[i] == stk[i + 1])
            {
                flag = 1;
                int j;
                for (j = i; j <= nn; j++)
                    if (stk[j] != stk[i])
                        break;
                i = j - 1;
            }
            else
            {
                stk[++top] = stk[i];
            }
        }
        cnt = top;
    }
    
    // for (int i = 1; i <= cnt; i++)
    //     printf("%d ", stk[i]);
    // puts("");
    return nn - cnt;
}

void solve(int t)
{
    printf("case #%d:\n", t);
    char s[N];
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - 'A' + 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 3; j++)
        {
            ans = max(ans, calc(i, j));
        }
    for (int i = 1; i <= 3; i++)
        ans = max(ans, calc(n + 1, i));
    printf("%d\n", ans);
}

int main(void)
{ 
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve(i);

    return 0;
}