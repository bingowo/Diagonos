#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long int dp[100][100]={0};
        for(int j=0;j<100;j++) dp[j][0]=1;
        dp[1][1]=1;
        int m,n;
        scanf("%d %d",&m,&n);
        for(int q=2;q<=m;q++)
        {
            for(int w=1;w<=n;w++)
            {
                dp[q][w]=dp[q-1][w-1]+dp[q-1][w];
            }
        }
        printf("case #%d:\n%lld\n",i,dp[m][n]);
    }
}
