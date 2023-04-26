#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cal(int num)
{
    int cnt = 0;
    while (num)
    {
        cnt += num & 1;
        num >>= 1;
    }
    return cnt;
}

int gcd(int u, int v)
{
    if (v == 0)
        return u;
    return gcd(v, u % v);
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i)
    {
        char s[130];
        // scanf("%[^\n]", s);
        gets(s);
        int len = strlen(s);
        char *p = s;
        int cnt = 0, numerator = 0, denominator = len * 8;

        // while (*p)
        for (int j = 0; j < len; ++j)
        {
            unsigned char c = s[j];
            for (int k = 0; k < 8; ++k)
            {
                numerator += c % 2;
                c >>= 1;
            }
            // numerator += cal(c);
            // p++;
        }
        int r = gcd(denominator, numerator);
        printf("%d/%d\n", numerator / r, denominator / r);
    }
    return 0;
}