#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string R(string s)
{
    string t = s.substr(0, 1) + s.substr(0, 1);
    if (s.size() > 0){
        if ((t = t + R(s.substr(1))) < s) s = t;
    }
    return s;
}

int main()
{
    string s;cin >> s;
    cout << R(s) << endl;
    return 0;
}
