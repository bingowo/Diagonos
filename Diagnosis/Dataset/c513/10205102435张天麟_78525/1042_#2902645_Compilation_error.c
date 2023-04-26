#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s,s1;
void dfs(int x,int n)
{
    int i;
    cout<<s1<<endl;
    if(x==s.length())return;
    for(i=n;i<s.length();i++)
    {
        s1.push_back(s[i]);
        dfs(x+1,i+1);
        s1.pop_back();
    }
}
int main()
{
    int n,i;
    string s2;
    cin>>n;
    for(i=0;i<n;i++)
    {
        s="";
        s1="";
        cin>>s2;
        sort(s2.begin(),s2.end());
        unique_copy(s2.begin(),s2.end(),back_inserter(s));
        cout<<"case #"<<i<<":";
        dfs(0,0);
    }
    return 0;
}