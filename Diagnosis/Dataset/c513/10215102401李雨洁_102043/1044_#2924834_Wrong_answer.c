#include <stdio.h>

int main()
{
    char s[100000] = {'\0'},a[100000] = {'\0'};
    int t = 0;
    gets(s);
    char *p = s;
    while (*p != '\0')
    {
        int j = 0;
        if (*p == '0' && *(p + 1) == 'x')
        {
            p = p + 2;
            int i = 0;
            while (*p >= '0' && *p <= '9' || *p >= 'A' && *p <= 'F' || *p >= 'a' && *p <= 'f')
            {
                a[j] = *p;
                p++;
                j++;
                i++;
            }
            if (i != 0)
            {
                j -= i;
                unsigned int num = 0;
                while (a[j] != '\0')
                {
                    if (a[j] >= '0' && a[j] <= '9')
                        num = num * 16 + a[j] - '0';
                    else if (a[j] >= 'A' && a[j] <= 'F')
                        num = num * 16 + a[j] - 'A' + 10;
                    else if (a[j] >= 'a' && a[j] <= 'f')
                        num = num * 16 + a[j] - 'a' + 10;
                    j++;
                }
                t++;
                printf("%u ", num);
            }
        }
        p++;
    }
    if (t == 0)
        printf("-1");
    return 0;
}
