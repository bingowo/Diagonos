#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>

void init(char* s, int* n){
    int i = 0;
    for(; i < 20; i++){
        n[i] = s[i] - '0';
    }
    n[19] = strlen(s);
}

long long dfs(int* n, long long (*dp)[9], int sum, int depth, int limit){
    long long ret = 0;

    if(depth >= n[19]) return (sum%9 == 0?0:1);

    int k = (limit == 1?n[depth]+1:9);
    for(int i = 0; i < k; i++){

        if(dp[depth+1][0] == 0 || (i == k-1 && limit == 1)) {
            ret += dfs(num, n, dp, (sum+i), depth+1, (i == k-1?limit:0));
        }
        else{
            for(int j = 0; j < 9; j++){
                if((sum+i+j)%9 != 0) ret += dp[depth+1][j];
            }
        }

        for(int j = 0;j < 9; j++){
            if(depth == n[19] - 1) dp[depth][j] = 1;
            else dp[depth][(j+i)%9] += dp[depth+1][j];
        }

    }

    return ret;
}

long long solve(int* n){
    long long dp[20][9];
    memset(dp, 0, sizeof(long long)*20*9);
    return dfs(n,dp,0,0,1);
}


int main(){
    char tmp1[20],tmp2[20];scanf("%s%s",tmp1,tmp2);
    int n1[20], n2[20];
    init(tmp1,n1);init(tmp2,n2);
    long long num1 = solve(n1), num2 = solve(n2);
    printf("%lld",num2-num1+1);
    return 0;
}
