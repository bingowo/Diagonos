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

int r;
ll n;

void solve(void)
{
    scanf("%lld %d", &n, &r);
    char s[106];
    int top = 0;
    int flag = 0;
    if (n < 0)
        flag = 1;
    n = abs(n);
    while (n)
    {
        int x = n % r;
        if (x < 10)
        {
            s[++top] = '0' + x;
        }
        else
        {
            s[++top] = 'A' + x - 10;
        }
        n /= r;
    }
    if (flag)
        putchar('-');
    while (top)
    {
        putchar(s[top]);
        top--;
    }
    puts("");
}

int main(void)
{ 
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}