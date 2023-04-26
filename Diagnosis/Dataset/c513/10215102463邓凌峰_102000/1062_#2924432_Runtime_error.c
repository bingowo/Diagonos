#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long int lli;



int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;scanf("%d",&n);
        lli dp[n+1];
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        dp[4]=8;
        for(int j=5;j<=n;j++){
            dp[j]=dp[j-1]+dp[j-2]+dp[j-3]+dp[j-4];
        }
        printf("case #%d:\n%lld",i,dp[n]);

    }

}

