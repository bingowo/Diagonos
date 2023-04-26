#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int k = 0, n = 0;
    scanf("%d%d",&k,&n);
    int dp[n];memset(dp,0,n*sizeof(int));
    dp[0] = 0;dp[1] = 1;
    for(int i = 2;i<n;i++){
        for(int j = i-k;j<i;j++){
            if(j>=0){
                dp[i]+=dp[j];
            }
        }
    }
    //for(int i = 0;i<n;i++){
    //    printf("%d\n",dp[i]);
    //}
    printf("%d\n",dp[n-1]);
    return 0;
}
