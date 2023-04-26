#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dp[21];memset(dp,0,21*sizeof(int));
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;
    for(int i = 4;i<21;i++){
        dp[i] = 2*dp[i-1] - dp[i-2] + dp[i-3];
    }

    int n = 0;
    while(1){
        scanf("%d",&n);
        if(n==-1){
            break;
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
