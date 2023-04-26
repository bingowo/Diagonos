#include <bits/stdc++.h>
using namespace std;
int del(string s,int pos,string c)
{
    s = s.insert(pos,c);
    int len = s.size();
    regex reg1("(.)\\1+");
    smatch sm;
    while (regex_search(s,sm,reg1)){
        s = regex_replace(s,reg1,"");
    }
    return len - s.size();
}
int main()
{
    int t;
    string s;
    cin>>t;
    for (int cas=0;cas<t;++cas){
        cin>>s;
        int ans = 0;
        for (int j=0;j<s.size()-1;++j){
            ans  = max(ans,del(s,j,"A"));
            ans  = max(ans,del(s,j,"B"));
            ans  = max(ans,del(s,j,"C"));
        }
        printf("case #%d:\n",cas);
        cout<<ans<<endl;
    }
}