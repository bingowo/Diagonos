#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define maxl 1000
#define max(a, b) (a > b) ? (a) : (b)
char a[maxl][maxl];

void add(char *s, char *t, char *u)
{
    /*pre condition:s and t are two numbers
    every character in s and t contain only '0'-'9'
    s and t should be positive numbers
    post condition:u is s+t
    make sure u has a length smaller than maxl
    */
    int i;
    int lens = strlen(s), lent = strlen(t);
    int k = max(lens, lent) + 1;
    for (i = 0; i < lens; i++)
        s[i] -= '0';
    for (i = 0; i < lent; i++)
        t[i] -= '0';
    int cc = 0, p = lens - 1, q = lent - 1;
    for (i = k; i >= 0; i--)
    {
        int x = cc;
        if (p >= 0)
            x += s[p], p--;
        if (q >= 0)
            x += t[q], q--;
        u[i] = x % 10 + '0';
        cc = x / 10;
    }
    u[k + 1] = '\0';
    while (u[0] == '0')
    {
        for (i = 0; i < k + 1; i++)
            u[i] = u[i + 1];
    }
    if (strlen(u) == 0)
    {
        u[0] = '0', u[1] = '\0';
    }
}

void fib(int n, int t)
{
    if (!t)
    {
        for (int i = 2; i < n + 1; i++)
        {
            char res[maxl];
            add(a[i - 1], a[i - 2], res);
            strcpy(a[i], res);
        }
    }
    if (n > t)
    {
        for (int i = t; i < n + 1; i++)
        {
            char res[maxl];
            add(a[i - 1], a[i - 2], res);
            strcpy(a[i], res);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    strcpy(a[0], "0"), strcpy(a[1], "1");
    int temp = 0;
    for (int z = 0; z < T; z++)
    {
        printf("case #%d:\n", z);
        int n;
        scanf("%d", &n);
        if (n > 1)
            fib(n, temp), temp = n;
        printf("%s\n", a[n]);
    }
    return 0;
}