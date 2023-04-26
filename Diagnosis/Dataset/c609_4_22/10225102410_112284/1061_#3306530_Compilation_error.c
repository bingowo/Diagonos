#include <stdio.h>
#define N 1005

int n;
long long dp[N][N];
int peimr[N];

int ck_prime(int x){
    for(int i = 2;i * i <= x;i++){
        if(x % i == 0) return 0;
    }
    return 1;
}

int sieve(){
    int cnt = 0;
    for(int i = 0;i < N;i++){
        if(c_prime(i)) prime[++cnt] = i;
    }
return cnt;

}

int main(){
    scanf("%d",&n);
    int np = sieve();
    dp[0][0] = 1;
    int i;
    for(i = 1;i <= np && prime[i] <= i; i++){
        for(int j = 0;j <= n;j++) dp[i][j] = dp[i - 1][j];
        for(int j = prime[i];j <= n;j++){
            for(int k  = 1;k *prime[i] <= j;k++){
                dp[i][j] += dp[i - 1][j - k * prime[i];
            }
        }
    }
    print("%lld\n",dp[i - 1][n]);
    return 0;
}

