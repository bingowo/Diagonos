#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",k);
        long long dp[51]={0,1,1,1,1};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=4;j++){
                if(i>j)dp[i]+=dp[i-j];
            }
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
