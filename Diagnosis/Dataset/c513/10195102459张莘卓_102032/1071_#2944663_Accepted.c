#include <stdio.h>
const int mod = 10007;
long long dp[1001][1001];

long long quickMult(int a, int k) {
    if(k == 0) return 1LL;
    int ans = 1;
    long long mult = a;
    while(k > 0) {
        if(k % 2) ans = mult * ans % mod;
        mult = mult * mult % mod;
        k /= 2;
    }
    return ans;
}

void set_dp(void) {
    for(int i=1; i<=1000; ++i){
        dp[i][0] = dp[i][i] = 1;
        for(int j=1; j<i; ++j)
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    set_dp();
    for(int i=0; i<T; ++i) {
        int a, b, k, n, m;
        scanf("%d %d %d %d %d",&a, &b, &k, &n, &m);
        if(k == 0){
            printf("case #%d:\n1\n",i);
            break;
        }
        long long ans = quickMult(a,n) * quickMult(b,m) % mod;
        ans = ans * dp[k][n] % mod;
        printf("case #%d:\n%d\n",i,(int)ans);
    }
}

