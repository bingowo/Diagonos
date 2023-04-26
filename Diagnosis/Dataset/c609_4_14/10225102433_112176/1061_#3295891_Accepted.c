#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1005

long long int dp[N][N];
int n;
int prime[10010];
int cnt;

int check(int num)
{
    int res = (int)sqrt(num);
    if(num <= 1) return 0;
    else if(num == 2) return 1;
    else{
        for(int i = 2;i <= res;i++){
            if(num%i == 0) return 0;
        }
        return 1;
    }
}

void putfill(int max)
{
    for(int i = 1;i <= max;i++){
        if(check(i)) prime[++cnt] = i;
    }
}

int main()
{
    //dp核心思想，分解到第i个素数时，整数j的分解方案数
    scanf("%d",&n);
    putfill(n);
    dp[0][0] = 1;
    for(int i = 1;i <= cnt;i++){
        for(int j = 0;j <= n;j++) dp[i][j] = dp[i-1][j];           //不取第i个数字
        for(int j = prime[i];j <= n;j++){
            for(int k = 1;k * prime[i] <= j;k++){                     //第i个数字取k次
                dp[i][j] += dp[i-1][j-k*prime[i]];
            }
        }
    }
    printf("%lld\n",dp[cnt][n]);
    return 0;
}