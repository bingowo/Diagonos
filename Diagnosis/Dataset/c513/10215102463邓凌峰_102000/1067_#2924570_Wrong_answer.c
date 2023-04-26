#include <stdio.h>
#include <stdlib.h>


typedef long long int lli;


int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;scanf("%d",&n);
        lli dp[74];
        dp[0]=0;dp[1]=dp[2]=1;
        for(int j=3;j<74;j++){
            dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
        }
        printf("case #%d:\n%d\n",i,dp[n]);
    }
}

