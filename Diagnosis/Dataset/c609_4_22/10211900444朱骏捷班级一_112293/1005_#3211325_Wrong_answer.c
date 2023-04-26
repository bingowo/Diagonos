#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int func(char *s)
{
    int dec = 0, m = 1;
    int len = strlen(s);
    for (int i = len - 1; i >= 0; --i)
    {
        int k;
        if (s[i] == '-')
            k = -1;
        if (s[i] == '0')
            k = 0;
        if (s[i] == '1')
            k = 1;
        dec += k * m;
        m *= 3;
    }
    return dec;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i)
    {
        char s[32];
        // scanf("%s", s);
        gets(s);
        int res = func(s);
        printf("case #%d:\n%d\n", i, res);
    }
    return 0;
}