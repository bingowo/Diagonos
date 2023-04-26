#include<stdio.h>
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int n;
    scanf("%d",&n);
    long long int dp[1001][5];
    for(int i=0;i<1001;i++)
    {
        dp[i][0]=0;
        dp[i][1]=1;
    }
    dp[0][0]=1;
    dp[0][1]=1;
    dp[0][2]=1;
    dp[0][3]=1;
    dp[0][4]=1;
    for(int i=1;i<1001;i++)
    {
        for(int j=2;j<5;j++)
        {
            dp[i][j]=dp[i][j-1]+dp[i-j][j,i-j];
        }
    }
    for(int i=0;i<n;i++)
    {
        int p;
        scanf("%d",&p);
        printf("%d\n",dp[p][4]);
    }
}

