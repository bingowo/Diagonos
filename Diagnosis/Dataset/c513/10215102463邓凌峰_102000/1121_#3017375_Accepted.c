#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 1000
#define BigNUm 10007
#define N 100000

void dfs(int *ans,int *weights,int pos,int sum,int n){
    if(sum>0) ans[sum]=1;
    if(pos==n) return;
    dfs(ans,weights,pos+1,sum,n);
    dfs(ans,weights,pos+1,sum+weights[pos],n);
    dfs(ans,weights,pos+1,sum-weights[pos],n);
}

int main(){
    int n;scanf("%d",&n);
    int weights[n];
    memset(weights,0,sizeof(weights));
    int max=0;
    for(int k=0;k<n;k++){
        scanf("%d",&weights[k]);
        max+=weights[k];
    }

    int dp[n+1][max+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;

    for(int pos=1;pos<=n;pos++){
        for(int sum=0;sum<=max;sum++){
            if(dp[pos-1][sum]){
                dp[pos][sum]=1;
                dp[pos][abs(sum+weights[pos-1])]=1;
                dp[pos][abs(sum-weights[pos-1])]=1;
            }
        }
    }

    for(int k=1;k<=max;k++){
        printf("%d",dp[n][k]);
    }

    return 0;
}

