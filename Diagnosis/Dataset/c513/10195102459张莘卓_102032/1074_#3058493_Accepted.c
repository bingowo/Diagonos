#include <stdio.h>
#include <string.h>
#define mod 210
#define M 1000000007

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0; t<T; ++t) {
        char s[101];
        scanf("%s",s);
        int n = 0;
        long long dp[100][mod] = {0};
        for(int i=0; s[i]; ++i) {
            n = (n*10 + s[i] - '0') % mod;
            ++dp[i][n];
        }
        for(int pos=1; s[pos]; ++pos) {
            n = 0;
            for(int i=pos; s[i]; ++i) {
                n = (n*10+s[i]-'0') % mod;
                for(int k=0; k<mod; ++k) {
                    dp[i][(k+n)%mod] += dp[pos-1][k];
                    dp[i][(k-n+mod)%mod] += dp[pos-1][k];
                    dp[i][(k+n)%mod] %= M;
                    dp[i][(k-n+mod)%mod] %= M;
                }
            }
        }
        long long ans = 0;
        int index = strlen(s)-1;
        for(int i=0; i<mod; ++i) 
            if(i%2==0 || i%3==0 || i%5==0 || i%7==0) 
                ans = (ans + dp[index][i]) % M;
        printf("%lld\n",ans);
    }
    return 0;
}