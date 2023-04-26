#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string R(string s)
{
    string t;
    if (s[0]){
        t = s.substr(0, 1) + s.substr(0, 1) + R(s.substr(1));
        if (t < s) s = t;
    }
    return s;
}
int main()
{
    string s;cin >> s;
    cout << R(s) << endl;
    return 0;
}

