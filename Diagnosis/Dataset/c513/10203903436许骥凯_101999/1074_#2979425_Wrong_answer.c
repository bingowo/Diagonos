#include<stdio.h>
#include<string.h>
#define N 210
#define MOD 1000000007

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        int dp[101][N] = {1};
        char s[101]; scanf("%s", s); int len = strlen(s);
        for (int j = 0; j < len; j++){  
            int digit = 0;
            for (int k = j; k < len; k++){
                digit = (digit * 10 + s[j] - '0') % N;
                for (int m = 0; m < N; m++){
                    int amidx = (m + digit) % N, smidx = (m - digit + N) % N;
                    dp[k+1][amidx] = (dp[k+1][amidx] + dp[j][m]) % MOD;
                    if (j) dp[k+1][smidx] = (dp[k+1][smidx] + dp[j][m]) % MOD;
                }
            }
        }
        int res = 0;
        for (int j = 0; j != N; j++)
            if (!(j % 2 && j % 3 && j % 5 && j %7))
                res = (res + dp[len][j]) % MOD;
        printf("%d\n", res);
    } 
}