#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100006
char s[N][106];
int n, a[N][106];

int calc(int p, int x)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += abs(a[i][p] - x);
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
        int pre = -1, c = 0, sum = 0;
        for (int j = 1; str[j]; j++)
        {
            sum++;
            if (str[j] != pre)
            {
                if (j != 1)
                    a[i][c] = sum - 1, sum = 1;
                s[i][++c] = str[j], pre = str[j];
            }
        } 
        a[i][c] = sum, sum = 0;
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

    int ans = 0;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; a[i][j]; j++)
    //         printf("%d ", a[i][j]);
    //     puts("");
    // }
    for (int i = 1; a[1][i]; i++)
    {
        int res = (1 << 30);
        int l = 0, r = 106;
        while (l + 2 < r)
        {
            int m1 = l + (r - l) / 3, m2 = l + (r - l) / 3 * 2;
            if (calc(i, m1) < calc(i, m2))
                r = m2;
            else
                l = m1;
        }
        for (int j = l; j <= r; j++)
            res = min(res, calc(i, j));
        ans += res;
    }


    printf("%d\n", ans);
    return 0;
}