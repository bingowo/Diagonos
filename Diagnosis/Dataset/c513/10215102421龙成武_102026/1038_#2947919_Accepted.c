//我这种办法没有办法做到以一个x起到x，y两个变量的作用，和PPT不太一样
//原因是，我枚举的点是直角点，这样每一次扩展都没法借用上一次的结果，但是结合F[i][j]后很好想
//ppt上的方法枚举的点是45°点，这样每一次扩展都可以借用上一次的结果，还能减小一层时间复杂度
//重刷的时候再写那种方法吧
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getmin(int a, int b);
int main()
{
    int n, m, k, s, ans, ** a, i, j, x, y, ** F, rd, rp, ld, lp;
    scanf("%d %d %d", &n, &m, &k);
    ans = 0;
    a = (int**)malloc(n * sizeof(int*));
    F = (int**)malloc(n * sizeof(int*));
    for (i = 0;i < n;i++)
    {
        a[i] = (int*)malloc(m * sizeof(int));
        F[i] = (int*)malloc(m * sizeof(int));
    }
    for (i = 0;i < n;i++)
    {
        for (j = 0;j < m;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0;i < n;i++)
    {
        F[i][0] = a[i][0];
        for (j = 1;j < m;j++)
        {
            F[i][j] = F[i][j - 1] + a[i][j];       //第i行，从第0个元素累加到第j个元素的和
        }
    }
    //从某行第c个元素到第b个元素的累加和为F[i][b]-F[i][c-1],即以第c个元素为始，以第b个元素为终，构成的边长
    for (i = 0;i < n;i++)
    {
        for (j = 0;j < m;j++)
        {
            rd = getmin(n - i, m - j);rp = getmin(i+1,m-j);ld = getmin(n-i, j+1);lp = getmin(i + 1, j + 1);
            if(rd>1)
            for (x = 1;x < rd;x++)    //向右向下可能构成的所有三角形
            {
                s = 0;
                for (y = 0;y <= x;y++)
                {
                    s += (F[i + y][j + x - y] - F[i + y][j]) + a[i + y][j];
                }
                if (s >= k) ans++;
            }
            if(rp>1)
            for (x = 1;x < rp;x++)
            {
                s = 0;
                for (y = 0;y <= x;y++)
                {
                    s += (F[i - y][j + x - y] - F[i - y][j]) + a[i -y][j];
                }
                if (s >= k) ans++;
            }
            if(ld>1)
            for (x = 1;x < ld;x++)
            {
                s = 0;
                for (y = 0;y <= x;y++)
                {
                    s += (F[i + y][j] - F[i + y][j - x + y]) + a[i + y][j-x+y];
                }
                if (s >= k) ans++;
            }
            if(lp>1)
            for (x = 1;x < lp;x++)
            {
                s = 0;
                for (y = 0;y <= x;y++)
                {
                    s += (F[i - y][j] - F[i - y][j - x + y]) + a[i - y][j - x + y];
                }
                if (s >= k) ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
int getmin(int a, int b)
{
    return a < b ? a : b;
}
