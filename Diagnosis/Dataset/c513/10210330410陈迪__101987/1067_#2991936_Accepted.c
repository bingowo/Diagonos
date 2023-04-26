#include<stdio.h>

long long dp[75];
long long T(int n)
{
    if(n==0) return 0;
    if(n==1||n==2) return 1;
    if(dp[n]) return dp[n];
    dp[n] = T(n-1)+T(n-2)+T(n-3);
    return dp[n];
}

int main()
{
    int N; scanf("%d",&N);
    for(int j=0;j<N;j++) {
        int n; scanf("%d",&n);
        printf("case #%d:\n%lld\n",j,T(n));
    }
    return 0;
}

