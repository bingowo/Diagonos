#include <stdio.h>#define N 1005
int n;long long dp[N] ;int prime[N];
int ck prime (int x){for(int i = 2;i * i<= x; i++)(if(x  i == 0)return 0;
return 1 ;
intsieve ()(int cnt = 0;for(int i = 2;i < N; i++){if(ck prime(i))prime[cnt++] = i;
return cnt ;
main() {intscanf("%d",&n);int np = sieve () ;dp[o] = 1;for(int i = 0; i < np && prime[i] <= n; i++){for(int j = prime[il; j <= n; j++){dp[j] += dp[j - prime[il];
printf("%lld\n",dp[n]) ;return 0 ;