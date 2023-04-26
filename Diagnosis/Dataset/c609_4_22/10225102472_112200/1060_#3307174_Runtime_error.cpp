#include<bits/stdc++.h>
using namespace std;
#define N 100

string R(string s)
{
    string t(2, s[0]);
    if(!s.empty())
    {
        string temp = R(s.substr(1));
        strcpy(&t[2], temp.c_str());
        t = t.substr(0, temp.size()+2);
        if(t < s)
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