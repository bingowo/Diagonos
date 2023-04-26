#include<stdio.h>

int main(){
    int t,n;
    scanf("%d",&t);
    int a[4]={4,3,2,1};
    while(t--){
        scanf("%d",&n);
        int dp[5][n+1];
        for(int i=0;i<5;i++){
            dp[i][0]=1;
            for(int j=1;j<=n;j++)dp[i][j]=0;
        }
        for(int j=1;j<=n;j++){
            for(int i=1;i<5;i++){
                for(int k=0;k<=j/a[i-1];k++)dp[i][j]+=dp[i-1][j-k*a[i-1]];
            }
        }
        printf("%d\n",dp[4][n]);
    }
}