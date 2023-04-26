#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int o,r;
    char m[10000];
    scanf("%d",&o);
    scanf("%s",m);
    scanf("%d",&r);
    int x = 0;
    for (int i = 0; m[i] != '\0'; i++)
    {
        if (m[i] - '0' < 10)
        {
            x = x * o + (m[i] - '0');
        }
        else
        {
            x = x * o + (tolower(m[i]) - 'a' + 10);
        }
    }

    if (x == 0)
    {
        printf("0");
        return 0;
    }
    char ans[1111];
    int i;
    for (i = 0; x > 0; i++, x /= r)
    {
        int n = x % r;
        if (n < 10)
        {
            ans[i] = n + '0';
        }
        else
        {
           ans[i] = n - 10 + 'A';
        }
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c",ans[j]);

    }

    return 0;
}
