#include<stdio.h>
#include<string.h>
#define M 210
#define MOD 1000000007

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        char s[101]; scanf("%s", s);
        int L = strlen(s);
        int f[101][210] = {1};
        for (int i = 0; i < L; i++){
            int sum = 0;
            for (int j = i; j < L; j++){
                sum = (sum * 10 + s[j] - '0') % M;
                for (int w = 0; w < M; w++){
                    f[j+1][(w + sum) % M] = (f[j+1][(w + sum) % M] + f[i][w])%MOD;
                    if (i) f[j+1][(w+M-sum) % M] = (f[j+1][(w+M-sum) % M] + f[i][w]) % MOD; 
                }
            }
        }
        long long int res = 0;
        for (int j = 0; j != M; j++){
            if (!(j % 2 && j % 3 && j % 5 && j % 7))
                res = (res + f[L][j]) % MOD;
        }
        printf("%lld\n", res);
    } 
}