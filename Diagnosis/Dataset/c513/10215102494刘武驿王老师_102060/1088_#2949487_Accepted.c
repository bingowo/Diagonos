#include<stdio.h>
int main()
{
    int pros;
    scanf("%d",&pros);
    long long int dp[42][42];
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<42;i++) dp[1][i]=0;
    for(int i=1;i<42;i++) 
    {
        dp[i][1]=i;
        dp[i][0]=1;
    }
    for(int i=2;i<41;i++) for(int j=2;j<41;j++) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    for(int i=0;i<pros;i++)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        printf("case #%d:\n%lld\n",i,dp[m][n]);
    }
}
