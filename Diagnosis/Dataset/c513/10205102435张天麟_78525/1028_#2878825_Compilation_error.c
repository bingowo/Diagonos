#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    char AorD;
    cin>>AorD;
    int x;
    while(!cin.eof())
    {
        cin>>x;
        s.insert(x);
    }
    if(AorD=='A')
    {
        for(auto iter=s.begin();iter!=s.end();++iter)
        {
            cout<<*iter<<" ";
        }
    }
    else
    {
        for(auto iter=s.rbegin();iter!=s.rend();++iter)
        {
            cout<<*iter<<" ";
        }
    }
    return 0;
}