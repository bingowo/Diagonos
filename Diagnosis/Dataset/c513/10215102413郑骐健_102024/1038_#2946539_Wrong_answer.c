#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sum[200][200];
int square(int r, int c, int n, int all, int dierction);
int s[220][220];

int main()
{
    int r, c, all;
    memset(sum, 0, sizeof(sum));
    scanf("%d%d%d", &r, &c, &all);
    for (int i = 1;i <= r;i++)
    {
        for (int z = 1;z <= c;z++)
        {
            scanf("%d", &s[i][z]);
            sum[i][z] = sum[i][z - 1] + s[i][z];
        }
    }
    int min = (r < c) ? r : c;
    int res = 0;
    if (r < c)
    {
        for (int i = 1;i <= c - min + 1;i++)
        {
            res += square(1, i, min, all, 1);
            res += square(1, i + min - 1, min, all, 2);
            res += square(min, i, min, all, 3);
            res += square(min, i + min - 1, min, all, 4);
        }
    }
    else if (r > c)
    {
        for (int i = 1;i <= c - min + 1;i++)
        {
            res += square(i, 1, min, all, 1);
            res += square(i, min, min, all, 2);
            res += square(min + i - 1, 1, min, all, 3);
            res += square(min + i - 1, min, min, all, 4);
        }
    }
    else
    {
        res += square(1, 1, min, all, 1);
        res += square(1, min, min, all, 2);
        res += square(min, 1, min, all, 3);
        res += square(min, min, min, all, 4);
    }
    printf("%d", res);
    return 0;
}
int square(int r, int c, int n, int all, int dierction)
{
    if (n < 2)return 0;
    int res = 0;
    int i;
    switch (dierction)
    {
    case 1://
    {
        for ( i = 2;i <=n;i++)
        {
            int num = 0;
            int r_ = r;
            for (int k = i;k > 0;k--)
            {
                num += sum[r_][c + k - 1] - sum[r_][c - 1];
                r_ += 1;
            }

            if (num >= all)
            {
                res += n - i + 1;
                break;
            }
        }
        return res + square(r + 1, c + 1, n - 1, all, dierction) + square(r + 1, c, n - 1, all, dierction) + square(r, c + 1, n - 1, all, dierction);
    }
    case 2://срио
    {
        for ( i = 2;i <=n;i++)
        {
            int num = 0;
            int r_ = r;
            for (int k = i;k > 0;k--)
            {
                num += sum[r_][c] - sum[r_][c - k];
                r_ += 1;
            }

            if (num >= all)
            {
                res += n - i + 1;
                break;
            }
        }
        return res + square(r + 1, c - 1, n - 1, all, dierction) + square(r + 1, c, n - 1, all, dierction) + square(r, c - 1, n - 1, all, dierction);
    }

    case 3://左下
    {
        for (i = 2;i <= n;i++)
        {
            int num = 0;
            int r_ = r;
            for (int k = i;k > 0;k--)
            {
                num += sum[r_][c +k- 1] - sum[r_][c - 1];
                r_ -= 1;
            }

            if (num >= all)
            {
                res += n - i + 1;
                break;
            }
        }
        return res + square(r - 1, c + 1, n - 1, all, dierction) + square(r - 1, c, n - 1, all, dierction) + square(r, c + 1, n - 1, all, dierction);
    }

    case 4://右下
    {
        for ( i = 2;i <= n;i++)
        {
            int num = 0;
            int r_ = r;
            for (int k = i;k > 0;k--)
            {
                num += sum[r_][c] - sum[r_][c - k];
                r_ -= 1;
            }

            if (num >= all)
            {
                res += n - i + 1;
                break;
            }
        }
        return res + square(r - 1, c - 1, n - 1, all, dierction) + square(r - 1, c, n - 1, all, dierction) + square(r, c - 1, n - 1, all, dierction);
    }
    }
}
