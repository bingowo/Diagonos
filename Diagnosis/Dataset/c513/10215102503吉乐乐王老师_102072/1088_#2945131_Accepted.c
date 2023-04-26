#include<stdio.h>
#include<stdlib.h>
int main(){
    int t;scanf("%d",&t);getchar();
    int cas=0;
    long long int dp[50][50];dp[0][0]=1;
    for(int i=1;i<50;i++){
        dp[i][0]=1;dp[0][i]=1;
    }
    for(int i=2;i<50;i++){
        for(int j=1;j<i;j++){
            dp[j][i-j]=dp[j-1][i-j]+dp[j][i-j-1];
        }
    }
    while(t--){
        int m,n;
        scanf("%d %d",&m,&n);
        printf("case #%d:\n%lld\n",cas++,dp[m-n][n]);
    }
}