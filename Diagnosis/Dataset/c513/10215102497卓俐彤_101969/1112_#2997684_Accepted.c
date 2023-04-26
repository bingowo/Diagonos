#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int dp[1001]={0};
    dp[0]=1;
    for(int i=1;i<=4;i++){
        for(int j=i;j<=1000;j++)
            dp[j]+=dp[j-i];
    }
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
