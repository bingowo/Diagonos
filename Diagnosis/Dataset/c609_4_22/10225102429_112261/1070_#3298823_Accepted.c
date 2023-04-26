#include <stdio.h>
#define N 21
long long dp[N];
long long d0[N];
long long d1[N];
int main(){
    int n;
    d0[1] = 1;
    d1[1] = 1;
    d0[2] = 2;
    d1[2] = 2;
    dp[1] = 2;
    dp[2] = 4;
    for(int i = 3; i<=N; i++){
        d0[i] = d0[i-1]+d1[i-1];
        d1[i] = d1[i-1]+d0[i-2];
        dp[i] = d0[i]+d1[i];
    }
    while(scanf("%d",&n)&&n!=-1){
        printf("%lld\n",dp[n]);
    }
    return 0;
}