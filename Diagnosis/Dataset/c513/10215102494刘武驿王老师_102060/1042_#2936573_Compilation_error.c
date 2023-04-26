#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
set<string> Combination(string s)
{
    string::iterator chas=s.begin();
    set<string> dp;
    string temp="";
    dp.insert(temp);
    for(;chas!=s.end();chas++)
    {
        set<string> dp1=dp;
        set<string>::iterator ele= dp1.begin();
        for(;ele!=dp1.end();ele++)
        {
            temp=*ele+*chas;
            dp.insert(temp);
        }
    }
    dp.erase(dp.begin());
    return dp;
}
int main(int argc, char** argv)
{  int T; cin>>T;
    for (int i=0;i<T;i++)
    {  string s,ss;  cin >> s;  sort(s.begin(),s.end());
        unique_copy(s.begin(),s.end(),back_inserter(ss));
        cout << "case #" <<  i << ":" << endl;
//********** Combination is called here **************
        for (const auto& x: Combination(ss)) cout << x << endl;
//**************************************************
   }
   return 0;
}

