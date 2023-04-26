#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,a[505][505],dp[505][505];
char dir[505][505],stk[10005];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            dp[i][j]=1e9;
        }
    dp[1][1]=a[1][1];
    //关键算法
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1)
                continue;
            if(i>1&&dp[i][j]>dp[i-1][j]+a[i][j])
            {
                dp[i][j]=dp[i-1][j]+a[i][j];
                dir[i][j]='D';
            }
            if(j>1&&dp[i][j]>dp[i][j-1]+a[i][j])
            {
                dp[i][j]=dp[i][j-1]+a[i][j];
                dir[i][j]='R';
            }
        }
    printf("%d\n",dp[n][m]);
    //输出路径
    int top=0,x=n,y=m;
    while(x!=1 || y!=1)
    {
        stk[++top]=dir[x][y];
        if(dir[x][y]=='R')
            y--;
        else
            x--;
    }
    for(int i=top;i;i--)
        printf("%c",stk[i]);
    return 0;
}
