#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pow(int N,int exp){
    int ans = 1;
    for(int i = 0;i<exp;i++){
        ans*=N;
    }
    return ans;
}
int main()
{
    //printf("%d",pow(10,4));
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        long long A = 0,B = 0,N = 0;
        scanf("%lld%lld%lld",&A,&B,&N);
        long long M = pow(10,N);
        long long dp[B];memset(dp,0,B*sizeof(long long));
        dp[0] = A%M;
        for(int j = 1;j<B;j++){
            dp[j] = ( (dp[j-1]%M)*(A%M) )%M;
        }

        char res[20];memset(res,0,20*sizeof(char));
        sprintf(res,"%lld",dp[B-1]);
        while(strlen(res)<N){
            char tmp[20] = "0";
            strcat(tmp,res);
            strcpy(res,tmp);
        }
        printf("case #%d:\n",i);
        printf("%s\n",res);
    }
    return 0;
}
