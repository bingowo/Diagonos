#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[501];
    scanf("%s", s);
    char a[2000] = {0};
    a[0] = '0';
    a[1] = '0';
    a[2] = '0';
    a[3] = '1';
    int l = strlen(s);
    int i, t = l;
    for (i = 13; i > 3; i--)
    {
        a[i] = t % 2 + '0';
        t = t >> 1;
    }
    int b, m = l;
    if (l % 3 == 2)
        m = l - 2;
    if (l % 3 == 1)
        m = l - 1;
    i = 13;
    for (int k = 2; k < m; k += 3)
    {
        b = (s[k] - '0') + (s[k - 1] - '0') * 10 + (s[k - 2] - '0') * 100;
        i += 10;
        for (int j = 0; j < 10; j++)
        {
            a[i - j] = b % 2 + '0';
            b = b >> 1;
        }
    }
    if (l % 3 == 2)
    {
        b = (s[m] - '0') * 10 + s[m + 1] - '0';
        i += 7;
        for (int j = 0; j < 7; j++)
        {
            a[i - j] = b % 2 + '0';
            b = b >> 1;
        }
    }
    if (l % 3 == 1)
    {
        b = s[m] - '0';
        i += 4;
        for (int j = 0; j < 4; j++)
        {
            a[i - j] = b % 2 + '0';
            b = b >> 1;
        }
    }
    a[i + 1] = '\0';
    printf("%s", a);

    return 0;
}