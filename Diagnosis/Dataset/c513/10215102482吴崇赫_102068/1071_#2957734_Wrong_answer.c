#include<stdio.h>
#include<stdlib.h>
#define N 10007
#define M 1005

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        int dp[M][M];
        for(int i=0;i<M;++i){
            for(int j=0;j<M;++j)dp[i][j]=1;
        }
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        dp[0][0]=1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if (i+j){
                    if (i==0) dp[i][j] = b*dp[i][j-1]%N;
                    else if (j==0) dp[i][j] = a*dp[i-1][j]%N;
                    else dp[i][j] = (a*dp[i-1][j]+b*dp[i][j-1])%N;
                }
            }
        }
        printf("case #%d:\n",x++);
        printf("%d\n",dp[n][m]);
    }
    return 0;
}