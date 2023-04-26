#include<stdio.h>
int main()
{
int w;
scanf("%d",&w);
while(w--){
    int n,p,m,t,dp[102][102]={0};
    scanf("%d",&n);
    scanf("%d",&p);
    scanf("%d",&m);
    scanf("%d",&t);
    dp[p][0]=1;
    dp[p][1]=0;
    dp[p][2]=2;
    int i,j;
    for(j=1;j<=m;j++){
        for(i=1;i<=n;i++){
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
