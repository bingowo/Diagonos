#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define ll long long
#define ull unsigned long long
using namespace std;

const int MAXLEN = 1000;

int main()
{
    string s, t;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        t = s;
        char c[2];
        sprintf(c, "%c", t[i]);
        t.insert(i, c);
        if (t.compare(s) < 0)
            len++, i++, s = t;
    }
    cout << s << endl;
    return 0;
}