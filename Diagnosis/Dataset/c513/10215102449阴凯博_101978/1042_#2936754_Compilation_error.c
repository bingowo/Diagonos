/***************************************************************/

/*                                                                                     */

/*  DON'T MODIFY main function ANYWAY!                     */

/*                                                                                      */

/***************************************************************/



#include <iostream>

#include <string>

#include <set>

#include <algorithm>

using namespace std;



//********** Specification of Combination **********


set<string> Combination(string s)
{
    if (s.empty())
        return {};
    else
    {
        set<string> result;
        string s1,s2;
        set<string> r1,r2,r3;
        s1=s.substr(0,1);
        s2=s.substr(1,s.size()-1);
        r1.insert(s1);
        r3=Combination(s2);
        int n=r3.size();
        for (string x:r3)
            r2.insert(s1+x);
        for (string x:r1)
            if (result.find(x)==result.end())
                result.insert(x);
        for (string x:r2)
            if (result.find(x)==result.end())
                result.insert(x);
        for (string x:r3)
            if (result.find(x)==result.end())
                result.insert(x);
        return result;
    }


};




int main()

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



