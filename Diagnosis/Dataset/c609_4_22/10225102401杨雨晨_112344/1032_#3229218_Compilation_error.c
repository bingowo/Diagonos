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

————————————————
版权声明：本文为CSDN博主「lose__way」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/lose__way/article/details/73135701