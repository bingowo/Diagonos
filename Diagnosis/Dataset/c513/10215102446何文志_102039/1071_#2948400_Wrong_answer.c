#include <stdio.h>
#include <stdlib.h>
#define N 10007
int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        int a = 0,b = 0,k = 0,n = 0,m = 0;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        int dp[n+1][m+1];memset(dp,0,(n+1)*(m+1)*sizeof(int));
        dp[0][0] = 1;
        for(int r = 1;r<m+1;r++){
            dp[0][r] = ((dp[0][r-1]%N)*(a%N))%N;

            //printf("dp[0][%d] = %d ",r,dp[0][r]);
            //if(r == m){printf("\n");}
        }
        for(int c = 1;c<n+1;c++){
            dp[c][0] = ((dp[c-1][0]%N)*(b%N))%N;
            //printf("dp[%d][0] = %d ",c,dp[c][0]);
            //if(c == n){printf("\n");}
        }

        for(int r = 1;r<n+1;r++){
            for(int c = 1;c<m+1;c++){
                int a1 = dp[r-1][c]%N,b1 = dp[r][c-1]%N;
                dp[r][c] = ( (a1*(a%N))%N + (b1*(b%N))%N )%N;
            }
        }

        printf("case #%d:\n",i);
        //for(int r = 0;r<n+1;r++){
        //    for(int c = 0;c<m+1;c++){
        //        printf("%d ",dp[r][c]);
        //    }
        //    printf("\n");
        //}
        printf("%d\n",dp[n][m   ]);
    }
    return 0;
}
