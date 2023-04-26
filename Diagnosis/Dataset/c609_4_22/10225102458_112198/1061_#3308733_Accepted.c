#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num,cnt=0;
    scanf("%d",&num);
    long long int dp[num+1];
    int number[1001],prime[1000];
    memset(dp,0,sizeof(dp));
    memset(number,0,sizeof(number));
    for(int i=2;i<=500;i++){
        for(int j=2;i*j<=1000;j++){
            number[i*j]=1;
        }
    }
    for(int i=2;i<1000;i++){if(!number[i])prime[cnt++]=i;}
    dp[0]=1;
    for(int i=0;i<cnt;i++){
        for(int j=1;j<=num;j++){
            if(j>=prime[i])dp[j]+=dp[j-prime[i]];
        }
    }

    printf("%lld\n",dp[num]);
    return 0;
}
