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

//long long combination(m,n){
//    if(n == 0||n==m){
//        return 1;
//    }
//    if(n == 1){
//        return m;
//    }
//    return combination(m-1,n)+combination(m-1,n-1);
//}

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
        //res = combination(m,n);

        //if(n == 0){
        //    printf("case #%d:\n",i);
        //    printf("1\n");
        //    continue;
        //}
        //if(n == 1){
        //    printf("case #%d:\n",i);
        //    printf("%d\n",m);
        //    continue;
        //}
        long long dp[n+1][m];memset(dp,0,(n+1)*m*sizeof(long long));
        for(int i1 = 0;i1<n+1;i1++){
            for(int j1 = 0;j1<m;j1++){
                if(i1 == j1+1){
                    dp[i1][j1] = 1;
                }
                else if(i1 == 0){
                    dp[i1][j1] = 1;
                }
                else if(i1 == 1){
                    dp[i1][j1] = j1+1;
                }
            }
        }

        for(int i1 = 1;i1<n+1;i1++){
            for(int j1 = 1;j1<m;j1++){
                dp[i1][j1] = dp[i1][j1-1]+dp[i1-1][j1-1];
            }
        }
        //dp[0][0] = 1;
        //for(int k = 0;k<m;k++){
        //    dp[0][k] = 1;
        //    dp[1][k] = k+1;
        //}
        //for(int j = 0;j<n+1;j++){
        //    dp[j+1][j] = 1;
        //}

        //for(int j = 1;j<n+1;j++){
        //    for(int k = j;k<m;k++){
        //        dp[j][k] = dp[j-1][k-1] + dp[j][k-1];
        //    }
        //}

        //for(int i1 = 0;i1<n+1;i1++){
        //    for(int j1 = 0;j1<m;j1++){
        //        printf("%lld ",dp[i1][j1]);
        //    }
        //    printf("\n");
        //}
        res = dp[n][m-1];
        printf("case #%d:\n",i);
        printf("%lld\n",res);
        //printf("%lld\n",dp[n][m-1]);
    }
    return 0;
}
