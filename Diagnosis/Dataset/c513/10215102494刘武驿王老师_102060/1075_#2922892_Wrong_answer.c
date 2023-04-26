#include<stdio.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int table[300][300];
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) scanf("%d",&table[i][j]);
    }
    int dp[300][300];
    dp[0][0]=table[0][0];
    for(int i=1;i<n;i++)
    {
        dp[0][i]=table[0][i]+dp[0][i-1];
    }
    for(int i=1;i<m;i++)
    {
        dp[i][0]=table[i][0]+dp[i-1][0];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(dp[i][j-1]<dp[i-1][j]) dp[i][j]=dp[i][j-1]+table[i][j];
            else dp[i][j]=dp[i-1][j]+table[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) printf("%d ",dp[i][j]);
        printf("\n");
    }
    int i=m-1,j=n-1;
    char dir[1000];
    int count=0;
    while(i!=0||j!=0)
    {
        if(j==0)
        {
            dir[count++]='D';
            i-=1;
            continue;
        }
        if(i==0)
        {
            dir[count++]='R';
            j-=1;
            continue;
        }
        if(dp[i-1][j]<dp[i][j-1])
        {
            dir[count++]='D';
            i=i-1;
        }
        else
        {
            dir[count++]='R';
            j-=1;
        }
    }
    dir[count]='\0';
    printf("%d\n",dp[m-1][n-1]);
    for(int i=count-1;i>=0;i--) printf("%c",dir[i]);
}