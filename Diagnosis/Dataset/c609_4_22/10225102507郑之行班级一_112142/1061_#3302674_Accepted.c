#include <stdio.h>
#include <stdlib.h>

#define N 1000

int primes[200];

void findprimes(int *primes)
{
    int i,j,b[N+1];//i:primes
    for(i=2;i<=N;i++)b[i]=1;
    for(i=2;i*i<N;i++)
        if(b[i])for(j=2;i*j<=N;j++)b[i*j]=0;
    for(i=2;i<=N;i++)if(b[i])*(primes++)=i;//if(b[i]==1) i is a prime
    *primes=N+1;//ENDING
}


long long search(int n,int start,int*primes){
    static long long ans[N+1][200]={0};
    if(!ans[n][start]){
        int i;
        if (!n)return ans[n][start]=1;
        for (i=start;primes[i]<=n;i++){
            ans[n][start]+=search(n-primes[i],i,primes);//next
        }
    }
    return ans[n][start];
}

long long search2(int n,int start,int*primes){
    long long dp[N+1]={1};
    for(int i=start;primes[i]<=n;i++){
        for(int x=primes[i];x<=n;x++){
            dp[x]+=dp[x-primes[i]];
        }
    }
    return dp[n];
}

int main()
{
    int in;scanf("%d",&in);
    findprimes(primes);
    //int cnt=0;while(primes[cnt]<=in)cnt++;//cnt--;
    //long long ans[N+1][200]={0};
    printf("%lld",search2(in,0,primes));
    return 0;
}