#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string R(string s)
{
    string t, s1;
    if (s[0]){
        s1 = R(s.substr(1));
        t = s.substr(0, 1) + s.substr(0, 1) + s1;
        if (t < s) s = t;
        else s = s.substr(0, 1) + s1;
    }
    return s;
}
int main()
{
    string s;cin >> s;
    cout << R(s) << endl;
    return 0;
}
