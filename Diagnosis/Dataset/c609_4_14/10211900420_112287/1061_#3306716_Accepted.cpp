#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define N 1000
void findprime(vector<int>& prime)
{
    int flag,j=0;
    for(int i=2;i<N;i++)
    {
        flag=1;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            prime[j]=i;
            j++;
        }
    }
}
long long search(int n,int start,vector<int>& prime)
{
    long long dp[N+1]={1};
    for(int i=start;prime[i]<=n;i++)
    {
        for(int x=prime[i];x<=n;x++)
        {
            dp[x]=dp[x]+dp[x-prime[i]];
        }
    }
    return dp[n];
}
int main()
{
    long long ans;
    int n;
    vector<int> prime(N);
    findprime(prime);
    cin>>n;
    ans=search(n,0,prime);
    cout<<ans;
    return 0;
}
