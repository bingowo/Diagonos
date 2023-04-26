#include<stdio.h>
#include<stdlib.h>

int main()

{
    int w;
    scanf("%d",&w);
    while(w--){
        int n,p,m,t,dp[102][102]={0};
        scanf("%d%d%d%d",&n,&p,&m,&t);
        dp[p][0]=1;
        dp[p][1]=0;
        dp[p][2]=2;
        int i,j;
        for(j=1;j<=m;j++){//分钟
            for(i=1;i<=n;i++){//在哪一栋
                if(i<n){
                    dp[i][j]=dp[i-1][j-1]+dp[i+1][j-1];
                }
                else{
                    dp[i][j]=dp[i-1][j-1];
                }
            }
        }
        printf("%d\n",dp[t][m]);
    }
}