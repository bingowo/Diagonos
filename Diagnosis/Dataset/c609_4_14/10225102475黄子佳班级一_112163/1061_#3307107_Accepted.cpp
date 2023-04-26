#include <iostream>
#include <vector>
#define N 1005
using namespace std;
int findprime(int n);

int main()
{
    int n;
    cin>>n;
    vector<int> prime;//小于n的所有素数
    int cnt{};
    for(int m=2;m<n;m++)
    {
        if(findprime(m))
        {
            prime.push_back(m);
            cnt++;
        }
    }
    vector<long long> dp(N);
    dp[0]=1;
    for(int i{};i<cnt&&prime[i]<=n;i++)
     {
         for(int j=prime[i];j<=n;j++)
         {
             dp[j]+=dp[j-prime[i]];
         }
     }
     cout<<dp[n]<<endl;
    return 0;
}

int findprime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
