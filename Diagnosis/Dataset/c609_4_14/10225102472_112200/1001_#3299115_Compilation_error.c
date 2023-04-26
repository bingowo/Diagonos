#include<bits/stdc++.h>
using namespace std;
const int N(100);

string R(string s)
{
    string t;
    if (!s.empty())
    {
        if (strcmp((t.push_back(s[0]), t.push_back(s[0]), t.append(R(s.substr(1))).substr(2).c_str()), s.c_str()) < 0)
        {
            return s;
        }
    }
}

int main()
{
    string s;
    cin >> s;
    cout << R(s) << endl;
    return 0;
}