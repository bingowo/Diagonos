#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    while (n - cnt)
    {
        char s[61];
        scanf("%s", s);

        // char xdigits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        int mask[128];
        int r = 0;
        for (int i = 0; i < 128; ++i)
            mask[i] = -1;

        char *p = s;
        mask[*p] = 1;
        while (*++p)
        {
            if (mask[*p] == -1)
            {
                mask[*p] = r;
                r = r ? r + 1 : 2; // 1023456...
            }
        }
        if (r < 2)
            r = 2;
        long long res;
        // char *q = s;
        p = s;
        while (*p)
            res = res * r + mask[*p++];
        printf("case #%d:\n%lld\n", cnt++, res);
    }
    return 0;
}