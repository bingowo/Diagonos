#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 50


int main()
{   int n,m;
    int dp[32][32]={0};
    for(int m=0;m<32;m++){
        dp[m][m]=1;
        for(int n=m+1;n<32;n++){
            dp[n][m]=2*dp[n-1][m]+(1<<n-m-1)-dp[n-m-1][m];
        }

    }
    scanf("%d%d",&n,&m);
    while(n!=-1 && m!=-1){
        printf("%d\n",dp[n][m]);
        scanf("%d%d",&n,&m);
    }

    return 0;
}



