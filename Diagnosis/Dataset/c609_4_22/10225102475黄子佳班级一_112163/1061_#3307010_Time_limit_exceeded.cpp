#include <iostream>
#include <vector>
#include <map>

using namespace std;
int findprime(int n);

int main()
{
    int n;
    cin>>n;
    vector<int> prime;//小于n的所有素数
    for(int m=2;m<n;m++)
    {
        if(findprime(m))
        {
            prime.push_back(m);
        }
    }
    map<pair<int,int>,long long> a;//a[{i,j}]
    int i;
    a[{0,0}]=1;
    for(i=1;prime[i]<=n;i++)
    {
        for(int j{};j<=n;j++)a[{i,j}]=a[{i-1,j}];
        for(int j=prime[i];j<=n;j++)
        {
            for(int k=1;k*prime[i]<=j;k++)
            {
                a[{i,j}]+=a[{i-1,j-k*prime[i]}];
            }
        }
    }
    cout<<a[{i-1,n}]<<endl;
    return 0;
}

int findprime(int n)
{
    if(n%2==0)return 0;
    for(int i=3;i*i<n;i+=2)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
