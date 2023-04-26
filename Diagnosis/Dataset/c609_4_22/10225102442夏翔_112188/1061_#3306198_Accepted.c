//1061
#include<stdio.h>
#include<string.h>
#include<math.h>
int prime[1010];
long long dp[1010];
int isprime(int n){
    if(n <= 3) return (n >= 2);
    if(n%6 != 1 && n%6 != 5) return 0;
    int s = sqrt(n);
    for(int i = 5; i <= s; i += 6){
        if(n%i == 0 || n%(i+2) == 0) return 0;
    }
    return 1;
}
int main(){
    int n, count=0;
    scanf("%d", &n);
    for(int i = 2; i <= n; i ++){
        if(isprime(i)) prime[count++] = i;
    }
    dp[0] = 1;
    for(int i = 0; i < count; i ++){
        for(int j = prime[i]; j <= n; j ++){
            dp[j] += dp[j-prime[i]];
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}