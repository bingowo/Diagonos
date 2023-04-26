#include <iostream>
#include <vector>

using namespace std;
const int N=1005;

int n;
vector<vector<long long>> dp(N,vector<long long>(N,0));
vector<int> prime(N);

int ck_prime(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return 0;
    }
    return 1;
}

int sieve()
{
    int cnt=0;
    for(int i=2;i<N;i++)
    {
        if(ck_prime(i)) prime[++cnt]=i;
    }
    return cnt;
}

int main()
{
    cin>>n;
    int np=sieve();
    dp[0][0]=1;
    int i;
    for(i=1;i<=np&&prime[i]<=n;i++)
    {
        for(int j=0;j<=n;j++) dp[i][j]=dp[i-1][j];
        for(int j=prime[i];j<=n;j++)
        {
            for(int k=1;k*prime[i]<=j;k++) dp[i][j]+=dp[i-1][j-k*prime[i]];
        }

    }
    cout<<dp[i-1][n]<<endl;
    return 0;
}


