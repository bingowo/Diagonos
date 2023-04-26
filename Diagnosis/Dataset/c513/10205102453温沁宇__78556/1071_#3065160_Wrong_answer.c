#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
#define N 10007

int f(int n,int m,int a,int b){
    static int dp[M][M]={1},i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i+j){
                if(i==0){
                    dp[i][j]=b*dp[i][j-1]%N;
                }
                else if(j==0){
                    dp[i][j]=a*dp[i-1][j]%N;
                }
                else{
                    dp[i][j]=(a*dp[i-1][j]+b*dp[i][j-1])%N;
                }
            }
        }
    }
    return dp[n][m];
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a,b,k,n,m;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        printf("case #%d:\n",i);
        printf("%d\n",f(n,m,a,b));
    }
    return 0;
}
