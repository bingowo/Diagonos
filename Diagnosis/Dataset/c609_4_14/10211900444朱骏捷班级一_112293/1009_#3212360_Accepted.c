#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        gets(s); // getline(cin, s);
        int len = strlen(s);
        char *p = s;
        int cnt = 0;
        while (*p)
        {
            unsigned char c = *p;
            for (int k = 0; k < 8; ++k)
            {
                cnt += c % 2;
                c >>= 1;
            }
            p++;
        }
        int r = gcd(len * 8, cnt);
        printf("%d/%d\n", cnt / r, len * 8 / r);
    }
    return 0;
}