#include <stdio.h>
#include <stdlib.h>

int prime[1010];

int check(int x){
    if (x==2) return 1;
    else {
        for (int i=2;i*i<=x;i++)
            if (x%i==0) return 0;
    }
    return 1;
}

long long dp[1000][1234];//分解到第i个质数，j的总方案数。

int main()
{
    int num=1;
    for (int i=2;i<=1000;i++){
        if (check(i)) {
            prime[num]=i;
            num++;
        }
    }
    int n;
    scanf("%d",&n);
    for (int i=0;i<=1000;i++) dp[i][0]=1;
    for (int j=1;j<=n;j++){
        int i;
        for (i=1;prime[i]<=j;i++){
            dp[i][j]=dp[i-1][j];
            for (int k=1;k*prime[i]<=j;k++){
                dp[i][j]+=dp[i-1][j-k*prime[i]];
            }
        }
        for (;i<=n;i++){
            dp[i][j]=dp[i-1][j];
        }
    }
    int i=1;
    while (prime[i]<=n)i++;
    printf("%lld\n",dp[i-1][n]);
    return 0;
}
