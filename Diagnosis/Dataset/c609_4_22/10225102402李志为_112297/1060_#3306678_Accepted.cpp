#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    int i, len;
    cin >> s;
    len = s.size();
    for (i = 0; i < len; i++) {
        t = s;
        s.insert(i, 1, s[i]);
        if (t < s) s = t;
        else len++, i++;
    }
    cout << s;
    return 0;
}