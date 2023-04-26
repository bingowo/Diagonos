#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define maxl 1000
#define max(a, b) (a > b) ? (a) : (b)


void add(char *s, char *t, char *u)
{
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

int main()
{
    int T;
    scanf("%d", &T);
    char a[maxl][maxl];
    strcpy(a[0], "0"), strcpy(a[1], "1");
    for (int i = 2; i < 120 + 1; i++)
    {
        char res[maxl], t1[maxl], t2[maxl];
        strcpy(t1, a[i - 1]), strcpy(t2, a[i - 2]);
        add(t1, t2, res);
        strcpy(a[i], res);
    }
    for (int z = 0; z < T; z++)
    {
        printf("case #%d:\n", z);
        int n;
        scanf("%d", &n);
        printf("%s\n", a[n]);

    }
    return 0;
}