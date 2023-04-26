#include<stdio.h>
#include<stdlib.h>
#define N 10007
#define M 1005

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        int dp[M][M]={1};
        int a,b,k,n,m;
        scanf("%d%d%d%d%d\n",&a,&b,&k,&n,&m);
        dp[0][0]=1;
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                if (i+j){
                    if (i==0) dp[i][j] = (b%N*dp[i][j-1]%N)%N;
                    else if (j==0) dp[i][j] = (a%N*dp[i-1][j]%N)%N;
                    else dp[i][j] = ((a%N*dp[i-1][j]%N)%N+(b%N*dp[i][j-1]%N)%N)%N;
                }
            }
        }
        printf("case #%d:\n",x++);
        printf("%d\n",dp[n][m]);
    }
    return 0;
}