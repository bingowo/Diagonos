#include<cstdio>
#include<iostream>
#include<algorithm>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(cin>>n)
    {
        priority_queue<long long,vector<long long>,greater<long long> >team;
        while(n--)
        {
            int t;
            cin>>t;
            team.push(t);
        }
        long long ans=0;
        while(team.size()!=1)
        {
            long long t=team.top();
            team.pop();
            t+=team.top();
            team.pop();
            team.push(t);
            ans+=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}

