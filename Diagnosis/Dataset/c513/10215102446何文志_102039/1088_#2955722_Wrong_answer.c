#include <stdio.h>
#include <stdlib.h>

long long fact(long long n){
    long long res = 1;
    while(n>0){
        res*=n;
        n--;
    }
    return res;
}

int main()
{

    //printf("%d\n",fact(5));
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        int m = 0,n = 0;
        scanf("%d%d",&m,&n);
        //long long nFact = fact(n),mFact = fact(m),nMinusMFact = fact(n-m);
        //long long res = (nFact/mFact)/nMinusMFact;
        //printf("hhh %lld %lld %lld\n",nFact,mFact,nMinusMFact);
        long long res = 0;
        if(n == 0){
            printf("case #%d:\n",i);
            printf("1\n");
            continue;
        }
        long long dp[n+1][m];memset(dp,0,(n+1)*m*sizeof(long long));


        dp[0][0] = 1;
        for(int k = 0;k<m;k++){
            dp[0][k] = 1;
            dp[1][k] = k+1;
        }


        for(int j = 1;j<n+1;j++){
            for(int k = j-1;k<m;k++){
                dp[j][k] = dp[j-1][k-1] + dp[j][k-1];
            }
        }

        //for(int j = 0;j<n+1;j++){
        //    for(int k = 0;k<m;k++){
        //        printf("%lld ",dp[j][k]);
        //    }
        //    printf("\n");
        //}

        printf("case #%d:\n",i);
        printf("%lld\n",dp[n][m-1]);
    }
    return 0;
}
