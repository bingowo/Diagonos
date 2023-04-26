#include <string.h>
#include <stdio.h>
int dp[1001][1001];
int P;
int f(int n, int m, int a, int b){
    if(dp[n][m]!=0) return dp[n][m];
    if(n==0&&m==0) return dp[n][m] = 1;
    if(m==0) dp[n][m] = (a%P* f(n-1,m,a,b))%P;
    else if(n==0) dp[n][m] = (b%P*f(n,m-1,a,b))%P;
    else dp[n][m] = (a%P*f(n-1,m,a,b)+b%P*f(n,m-1,a,b))%P;
    return dp[n][m];
}
int main(){
    int t;
    P = 10007;
    scanf("%d",&t);
    for(int i = 0; i<t; i++){
        int a,b,k,n,m;
        printf("case #%d:\n",i);
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        printf("%d\n",f(n,m,a,b));
        memset(dp,0,sizeof dp);
    }
    return 0;
}