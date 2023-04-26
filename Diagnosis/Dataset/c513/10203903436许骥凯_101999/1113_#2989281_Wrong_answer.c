#include<stdio.h>
int dp[101] = {0,0,1}, cnt = 3;

int main(){
    int n, k; scanf("%d%d", &k, &n);
    if (n < cnt){
        printf("%d\n", dp[n]);
        return 0;
    }
    while(cnt <= n){
        for (int i = 0; i < k; i++){
            while (cnt + i < k) i++;
            dp[cnt] += dp[cnt - k + i];
        }
        cnt++;
    }
    printf("%d\n", dp[n]);
    return 0;
}
