#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2&&n!=-1&&m!=-1){
        getchar();
        int dp[32][32]={0};
        for(int i=1;i<32;i++)dp[i][i]=1;
        for(int i=2;i<32;i++){
            for(int j=1;j<i;j++){
                dp[i][j]=dp[i-1][j]*2+pow(2,i-1-j)-dp[i-1-j][j];
            }
        }
        printf("%d\n",dp[n][m]);
    }
}