#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define M 1001
#define N 10007
int f(int n,int m,int a,int b){
    static int dp[M][M]={1},i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i+j){
                if(i==0)dp[i][j]=(b%N*dp[i][j-1]%N)%N;
                else if(j==0)dp[i][j]=(a%N*dp[i-1][j]%N)%N;
                else dp[i][j]=((b%N*dp[i][j-1]%N)%N+(a%N*dp[i-1][j]%N)%N)%N;
            }
        }
    }
    return dp[n][m];
}


int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int a,b,k,m,n;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        int res=f(n,m,a,b);
        printf("case #%d:\n%d\n",t,res);
    }
    return 0;
}

