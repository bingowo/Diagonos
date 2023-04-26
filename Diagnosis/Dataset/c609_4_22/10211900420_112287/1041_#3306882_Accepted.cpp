#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

//********** Specification of Combination **********
set<string> Combination(string s)
{
    string c;
     set<string> s1,s2;
     if(s.empty())
     {
         return set<string>{};
     }
     else
     {
         c=s.substr(0,1);
         s1=Combination(s.substr(1,s.size()));
         s2=s1;
         for(const auto& m:s1) s2.insert(c+m);
         s2.insert(c);
         return s2;
     }
}

/***************************************************************/


int main( )
{  int T; cin>>T;
    for (int i=0;i<T;i++)
    {   string s,ss;  cin >> s;  sort(s.begin(),s.end());
        unique_copy(s.begin(),s.end(),back_inserter(ss));
        cout << "case #" <<  i << ":" << endl;

//********** Combination is called here **************
        for (const auto& x: Combination(ss)) cout << x << endl;
//**************************************************

   }
   return 0;
}