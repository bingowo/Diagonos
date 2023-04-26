#include<stdio.h>
#define N 105

unsigned long long int nsum(long long a[],int start,int n)
{
    unsigned long long int ret=0;
    for(int i=0,k=start;i<n;++i,--k){
        ret+=a[k];
    }
    return ret;
}

int main()
{
    unsigned long long int dp[N];for(int i=0;i<N;++i)dp[i]=0;
    int n,k;dp[0]=0;dp[1]=0;dp[2]=1;
    scanf("%d%d",&k,&n);
    if(k==2){
        for(int i=3;i<=n;++i)dp[i]=nsum(dp,i-1,2);
    }
    if(k==3){
        for(int i=3;i<=n;++i)dp[i]=nsum(dp,i-1,3);
    }
    if(k==4){
        dp[3]=1;
        for(int i=4;i<=n;++i)dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
    }
    if(k==5){
        dp[3]=1;dp[4]=2;
        for(int i=5;i<=n;++i)dp[i]=nsum(dp,i-1,5);
    }
    if(k==6){
        dp[3]=1;dp[4]=2;dp[5]=4;
        for(int i=6;i<=n;++i)dp[i]=nsum(dp,i-1,6);
    }
    if(k==7){
        dp[3]=1;dp[4]=2;dp[5]=4;dp[6]=8;
        for(int i=7;i<=n;++i)dp[i]=nsum(dp,i-1,7);
    }
    if(k==8){
        dp[3]=1;dp[4]=2;dp[5]=4;dp[6]=8;dp[7]=16;
        for(int i=8;i<=n;++i)dp[i]=nsum(dp,i-1,8);
    }
    if(k==9){
        dp[3]=1;dp[4]=2;dp[5]=4;dp[6]=8;dp[7]=16;dp[8]=32;
        for(int i=9;i<=n;++i)dp[i]=nsum(dp,i-1,9);
    }
    if(k==8){
        dp[3]=1;dp[4]=2;dp[5]=4;dp[6]=8;dp[7]=16;dp[8]=32;dp[9]=64;
        for(int i=10;i<=n;++i)dp[i]=nsum(dp,i-1,10);
    }
    printf("%llu\n",dp[n]);
}