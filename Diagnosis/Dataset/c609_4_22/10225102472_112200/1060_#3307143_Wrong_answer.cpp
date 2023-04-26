#include<bits/stdc++.h>
using namespace std;
#define N 100

string R(string s)
{
    string t = "";
    if(!s.empty())
    {
        if((t += s[0] + R(s.substr(1)).substr(0, s.size()-1)) < s)
        {
            s = t;
        }
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    cout << R(s);
    return 0;
}