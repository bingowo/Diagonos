#include <string>
#include <iostream>
#include <vector>
using namespace std;
int numplus(char ch, string s, int iter)
{
    int t = s.size();
    for (int i = iter; i < t; ++i)
    {
        if (s[i] > ch)
        {
            return 2 * (i - iter);
        }
    }
    return 1;
}

int main()
{
    string s, ret;
    cin >> s;
    int n = s.size();
    int i = 0;
    while (i < n - 1)
    {

        if (s[i] < s[i + 1])
        {
            ret.append(2, s[i]);
            ++i;
        }
        else if (s[i] > s[i + 1])
        {
            ret += s[i];
            ++i;
        }
        else
        {
            int m = numplus(s[i], s, i);
            ret.append(m, s[i]);
            i += m;
        }
    }
    cout << ret << endl;
    return 0;
}
