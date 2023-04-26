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
    //逐个相加
    for (int p1 = 1;p1 < r;p1++)
    {
        for (int p2 = 1;p2 < c;p2++)
        {
            min = (c - p2 < r - p1) ? c - p2+1 : r - p1+1;
            res += square(p1, p2, min, all, 1);
        }
    }

    for (int p1 = 1;p1 < r;p1++)
    {
        for (int p2 = c;p2 >1;p2--)
        {
            min = (p2 <  r-p1+1) ?  p2 : r- p1+1;
            res += square(p1, p2, min, all, 2);
        }
    }  
    
    for (int p1 = r;p1 >1 ;p1--)
    {
        for (int p2 = 1;p2 < c;p2++)
        {
            min = (p1 < c-p2+1) ? p1 : c - p2+1;
            res += square(p1, p2, min, all, 3);
        }
    }    
    
    for (int p1 = r;p1 > 1;p1--)
    {
        for (int p2 = c;p2 >1 ;p2--)
        {
            min = ( p2 <  p1) ?  p2: p1;
            res += square(p1, p2, min, all, 4);
        }
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
        return res ;
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
        return res ;
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
        return res ;
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
        return res ;
    }
    }
}
