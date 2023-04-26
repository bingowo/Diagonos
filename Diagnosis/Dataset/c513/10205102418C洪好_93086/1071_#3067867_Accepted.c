#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 1000
#define BigNUm 10007

typedef unsigned long long ull;




ull find(ull n,ull m,ull a,ull b){
    static ull dp[LEN+1][LEN+1]={1};
    int x,y;
    for(x=0;x<=n;x++){
        for(y=0;y<=m;y++){
            if(x+y){
                if(x==0){
                    dp[x][y]=dp[x][y-1]*b%BigNUm;
                }
                else if(y==0){
                    dp[x][y]=dp[x-1][y]*a%BigNUm;
                }
                else{
                    dp[x][y]=(a*dp[x-1][y]+b*dp[x][y-1])%BigNUm;
                }
            }
        }
    }
    return dp[n][m];

}

int main()
{

    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        ull a,b,k,n,m;
        scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
        printf("case #%d:\n",I);
        printf("%llu\n",find(n,m,a,b));
    }

    return 0;
}
