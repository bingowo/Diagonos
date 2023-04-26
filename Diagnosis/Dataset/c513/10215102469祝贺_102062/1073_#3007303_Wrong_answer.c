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

long long dfs(int* num, int* n, int (*dp)[10], int sum, int depth, int limit){
    long long ret = 0;

    if(depth >= n[19]) return (sum%9 == 0?0:1);

    int k = (limit == 1?n[depth]+1:9);
    for(int i = 0; i < k; i++){

        if(i == 0 || depth == n[19] - 1 || (i == k-1 && limit == 1)) {
            ret += dfs(num, n, dp, (sum+i)%9, depth+1, (i == k-1?limit:0));
        }
        else{
            for(int j = 0; j < 9; j++){
                if((sum+i+j)%9!=0) ret += dp[depth+1][j];
            }
        }

        if(depth != n[19]-1){
            for(int j = 0;j < 9; j++){
                dp[depth][(j+i)%9] += dp[depth+1][j];
            }
        }

    }

    return ret;
}

long long solve(int* n){
    int dp[20][9];
    memset(dp, 0, sizeof(int)*20*9);
    for(int i = 0; i < 9; i++)dp[n[19]-1][i]=1;
    int num[20]={0};
    return dfs(num,n,dp,0,0,1);
}


int main(){
    char tmp1[20],tmp2[20];scanf("%s%s",tmp1,tmp2);
    int n1[20], n2[20];
    init(tmp1,n1);init(tmp2,n2);
    long long num1 = solve(n1), num2 = solve(n2);
    printf("%lld",num2-num1+1);
    return 0;
}
