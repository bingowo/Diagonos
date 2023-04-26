#include <stdio.h>
#define MAXN 50
long long dp[MAXN+1]={0};
long long count_ways(int n) {
    int i,j;
    dp[0]=dp[1]=1;
    for(i=2;i<=n;i++){
        dp[i]=0;
        for(j=1;j<=4&&j<=i;j++) {
            dp[i]+=dp[i-j];
        }
    }
    return dp[n];
}
int main() {
    int T,n,i;
    scanf("%d",&T);
    for (i=0;i<T;i++) {
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,count_ways(n));
    }
    return 0;
}