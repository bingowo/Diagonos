#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define mod 10007
long long int mypow(long long int base,int p){
    long long int ret=1;
    base=base%mod;
    while(p>0){
        if(p%2==1)ret=(ret*base)%mod;
        p/=2;
        base=(base*base)%mod;
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    long long int **dp=(long long int**)malloc(sizeof(long long int*)*1001);
    for(int i=0;i<1001;i++){
        dp[i]=(long long int*)malloc(sizeof(long long int)*1001);
    }
    while(t--){
        int a,b,k,n,m;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        for(int i=0;i<=k;i++){
            dp[i][0]=1;dp[0][i]=1;
        }
        for(int i=2;i<=k;i++){
            for(int j=1;j<i;j++){
                dp[j][i-j]=(dp[j-1][i-j]+dp[j][i-j-1])%mod;
            }
        }
        long long int ret=(((dp[n][m]%mod)*(mypow(a,n)%mod)%mod)*(mypow(b,m)%mod))%mod;
        printf("case #%d:\n%lld\n",cas++,ret);
    }
}