//dp\1068.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/

#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

int dp[33][33]={0};
void initia_dp()
{
    dp[1][1]=1;
    dp[2][1]=3;
    dp[2][2]=1;
    dp[3][1]=7;
    dp[3][2]=3;
    dp[3][3]=1;
    for(int in=3;in<=32;++in){
        dp[in][1]=(1<<in)-1;
    }
}

int getans(int n,int m)
{
    if(n<=0||m<=0)
        return 0;
    if(n<m){
        dp[n][m]=0;
    }else if(n==m){
        dp[n][m]=1;
    }else{
        if(dp[n][m]==0)
            dp[n][m]=2*getans(n-1,m)-getans(n-m-1,m)+(1<<(n-1-m));
    }
    return dp[n][m];
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n,m;
    initia_dp();
    while(scanf("%d %d",&n,&m),n!=-1&&m!=-1){
        printf("%d\n",getans(n,m));
    }
}