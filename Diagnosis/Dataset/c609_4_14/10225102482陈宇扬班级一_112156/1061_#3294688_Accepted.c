#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LL long long int

int n;
int prime[1005];
LL dp[1005];

int check_prime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}
int sieve(){
    int cnt = 0;
     for(int i = 2; i < 1005; i++){
        if(check_prime(i))
            prime[cnt++] = i;
    }
    return cnt;
}

int main(){
    scanf("%d", &n);
    int np = sieve();
    dp[0] = 1;
    for(int i = 0; i <= np && prime[i] <= n; i++){
        for(int j = prime[i]; j <= n; j++){
            dp[j] += dp[j - prime[i]];
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}
