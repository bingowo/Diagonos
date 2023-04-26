#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100006
char s[N][106];
int n, a[N];

int calc(int x)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += abs(a[i] - x);
    return sum;
}

int min(int a, int b)
{
    return a > b ? b: a;
}

int main(void)
{ 
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char str[106];
        scanf("%s", str + 1);
        a[i] = strlen(str + 1);
        int pre = 0, c = 0;
        for (int j = 1; str[j]; j++)
            if (str[j] != pre)
                s[i][++c] = str[j], pre = str[j];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; s[i][j] || s[1][j]; j++)
            if (s[i][j] != s[1][j])
            {
                printf("%d\n", -1);
                return 0;
            }
    }

    int ans = (1 << 29);
    for (int i = 0; i <= 101; i++)
        ans = min(ans, calc(i));
    printf("%d\n", ans);
    return 0;
}