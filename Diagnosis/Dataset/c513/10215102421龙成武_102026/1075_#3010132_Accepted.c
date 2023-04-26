#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int** a;
typedef struct
{
    long long len;
    char step;              //要存这一格的上一步，因为不能像树的遍历直接打印，会多出一些没必要的打印
    int m, n;
}road;
road dp[201][201];
int mymin(long long a, long long b)
{
    return a < b ? 1 : 0;
}
road func(int m, int n)
{
    if (dp[m][n].len == -1)
    {
        if (m == 0 && n == 0)
        {
            dp[m][n].len = a[0][0];
        }
        else if (m == 0)
        {
            dp[m][n].len = func(m, n - 1).len + a[m][n];
            dp[m][n].step = 'R';
            //printf("R");
        } 
        else if (n == 0)
        {
            dp[m][n].len = func(m - 1, n).len + a[m][n];
            //printf("D");
            dp[m][n].step = 'D';
        }
        else
        {
            if (mymin(func(m - 1, n).len, func(m, n - 1).len) == 1)
            {
                dp[m][n].len = func(m - 1, n).len + a[m][n];
                dp[m][n].step = 'D';
            }
            else
            {
                dp[m][n].len = func(m, n-1).len + a[m][n];
                dp[m][n].step = 'R';
            }
        }
    }
    return dp[m][n];
}
void myPrint(int m,int n)
{
    if (m == 0 && n == 0)
        return;
    else if (dp[m][n].step == 'R')
    {
        myPrint(m, n - 1);
        printf("R");
    }
    else
    {
        myPrint(m - 1, n);
        printf("D");
    }
}
int main()
{
    int M, N, i, j;
    long long res=0;
    road x;
    scanf("%d%d", &M, &N);
    a = (int**)malloc(M * sizeof(int*));
    for (i = 0;i < M;i++)
    {
        a[i] = (int*)malloc(N * sizeof(int));
        for (j = 0;j < N;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    //memset(dp, -1, sizeof(dp));
    for (i = 0;i < 201;i++)
    {
        for (j = 0;j < 201;j++)
        {
            dp[i][j].len = -1;
            dp[i][j].m = i;
            dp[i][j].n = j;
        }
    }
    x = func(M - 1, N - 1);
    printf("%lld\n", x.len);
    myPrint(x.m,x.n);               //其实就是M-1和N-1
    return 0;
}
