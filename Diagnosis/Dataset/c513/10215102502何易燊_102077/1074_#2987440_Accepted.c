#include <stdio.h>
#include <string.h>
#define M 210
#define MOD 1000000007

int main()
{
    int n; scanf("%d",&n);
    while (n--)
    {
        char s[101] = {}; scanf("%s",s);
        int len = strlen(s);
        int dp[101][210] = {1};
        for (int i=0;i<len;i++)
        {
            int sum = 0;
            for (int j=i;j<len;j++)
            {
                sum = (sum*10+s[j]-'0')%M;
                for (int k=0;k<M;k++)
                {
                    dp[j+1][(k+sum)%M] = (dp[j+1][(k+sum)%M]+dp[i][k])%MOD;
                    if (i) dp[j+1][(k+M-sum)%M] = (dp[j+1][(k+M-sum)%M]+dp[i][k])%MOD;
                }
            }
        }
        int ans = 0;
        for (int i=0;i<M;i++)
        {
            if (i%2==0||i%3==0||i%5==0||i%7==0) ans = (ans%MOD+dp[len][i]%MOD)%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}