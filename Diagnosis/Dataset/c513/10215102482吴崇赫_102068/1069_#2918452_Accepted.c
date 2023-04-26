#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
#define M 1005

void reverse(char* s)
{
    char t;
    for(int i=0,j=strlen(s)-1;i<j;++i,--j){
        t=s[i];s[i]=s[j];s[j]=t;
    }
}

char* longtos(long long n)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]='\0';
    int p=0;
    while(n){
        ret[p++]=n%10+'0';
        n/=10;
    }
    reverse(ret);
    return ret;
}

int huiwen(char* s)
{
    for(int i=0,j=strlen(s)-1;i<j;++i,--j){
        if(s[i]!=s[j])return 0;
    }
    return 1;
}

int main()
{
    long long n;scanf("%lld",&n);
    long long dp[M];

    for(int i=0;i<M;++i)dp[i]=0;
    dp[0]=n;//int p=0;
    for(int i=0;i<M-1;++i){
        char fan[N]={'\0'};
        strcpy(fan,longtos(dp[i]));
        reverse(fan);long long m=atoll(fan);
        //printf("%lld\n",m);
        long long s=m+dp[i];
        //printf("%lld\n",s);
        if(huiwen(longtos(s))){
            printf("%d %lld",i+1,s);
            break;
        }
        else{
            dp[i+1]=s;
        }
    }

    //printf("%lld",m);
    return 0;
}
