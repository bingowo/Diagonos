#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct SSS
{
    long long value;
    char direction;
}sss;
int a[201][201];
sss dp[201][201];
void path(int m,int n)
{
    dp[0][0].value = a[0][0];
    for(int i = 1; i < m; i++)
    {
        dp[i][0].value = dp[i-1][0].value + a[i][0];
        dp[i][0].direction='D';
    }
    for(int i = 1; i < n; i++)
    {
        dp[0][i].value = dp[0][i-1].value + a[0][i];
        dp[0][i].direction='R';
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(dp[i-1][j].value<dp[i][j-1].value)
            {
                dp[i][j].value = dp[i-1][j].value+a[i][j];
                dp[i][j].direction='D';
            }
            else
            {
                dp[i][j].value = dp[i][j-1].value+a[i][j];
                dp[i][j].direction='R';
            }
        }
    }
}
void show(int m,int n)
{
    if(m==0 && n==0) return;
    if(dp[m][n].direction=='D')
    {
        show(m-1,n);
        printf("D");
    }
    else
    {
        show(m,n-1);
        printf("R");
    }
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    path(m,n);
    printf("%lld\n",dp[m-1][n-1]);
    show(m-1,n-1);
    return 0;
}
