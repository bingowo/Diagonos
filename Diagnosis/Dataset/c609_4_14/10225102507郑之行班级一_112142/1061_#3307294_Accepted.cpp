#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

#define N 1000

using namespace std;

void findprimes(vector<int> &primes)
{
    int i,j,b[N+1];//i:primes
    for(i=2;i<=N;i++)b[i]=1;
    for(i=2;i*i<N;i++)
        if(b[i])for(j=2;i*j<=N;j++)b[i*j]=0;
    for(i=2;i<=N;i++)if(b[i])primes.push_back(i);//if(b[i]==1) i is a prime
    primes.push_back(N+1);//ENDING
}

long long search2(int n,int start,vector<int> primes){
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
    vector<int> primes;
    findprimes(primes);
    cout<<search2(in,0,primes)<<endl;
    return 0;
}
