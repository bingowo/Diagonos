#include<stdio.h>
#define N 102

int main()
{
    int cas;
    scanf("%d\n",&cas);
    while(cas--){
        int dp[N][N];
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j)dp[i][j]=0;
        }
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        dp[p][0]=1;
        for(int j=1;j<=m;++j){
            for(int i=1;i<=n;++i)dp[i][j]=dp[i-1][j-1]+dp[i+1][j-1];
        }
        printf("%d\n",dp[t][m]);
    }
    return 0;
}
