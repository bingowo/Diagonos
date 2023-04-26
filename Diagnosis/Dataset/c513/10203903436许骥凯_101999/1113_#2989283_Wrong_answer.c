#include<stdio.h>
#define ll long long
ll dp[101] = {0,0,1}; int cnt = 3;

int main(){
    int n, k; scanf("%d%d", &k, &n);
    if (n < cnt){
        printf("%lld\n", dp[n]);
        return 0;
    }
    while(cnt <= n){
        for (int i = 0; i < k; i++){
            while (cnt + i < k) i++;
            dp[cnt] += dp[cnt - k + i];
        }
        cnt++;
    }
    printf("%lld\n", dp[n]);
    return 0;
}
