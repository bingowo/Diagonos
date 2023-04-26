#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N = 1000000010;

struct FLOAT
{
    string num;
    int sign;
    int int_len;
    string integer;
    string fraction;
};

bool cmp(const FLOAT &f1, const FLOAT &f2)
{
    if (f1.sign == f2.sign)
    {
        int x = f1.integer.compare(f2.integer);
        int ssign = f1.sign;
        if (f1.int_len == f2.int_len)
        {
            if (x)
                return ssign ? f1.integer > f2.integer : f1.integer < f2.integer;
            else
                return ssign ? f1.fraction > f2.fraction : f1.fraction < f2.fraction;
        }
        else
            return ssign ? f1.int_len > f2.int_len : f1.int_len < f2.int_len;
    }
    else
        return f1.sign < f2.sign;
}

void Stringsplit(const string &str, const char split, vector<string> &res)
{
    string strs = str + split;
    size_t pos = strs.find(split);
    while (pos != strs.npos)
    {
        string temp = strs.substr(0, pos);
        res.push_back(temp);
        strs = strs.substr(pos + 1, strs.size());
        pos = strs.find(split);
    }
}

void preprocess(FLOAT &p)
{
    string s = p.num;
    if (s[0] == '-')
        p.sign = -1;
    else
        p.sign = 0;
    if (s[0] == '-' || s[0] == '+')
        s.erase(0, 1);
    vector<string> strList;
    Stringsplit(s, '.', strList);
    p.integer = strList[0];
    p.int_len = p.integer.length();
    if (strList.size() > 1)
        p.fraction = strList[1];
    else
        p.fraction = "0";
}

int main()
{
    int n;
    cin >> n;
    vector<FLOAT> arr(n);
    for (auto &i : arr)
    {
        cin >> i.num;
        preprocess(i);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (auto &i : arr)
        cout << i.num << endl;
    return 0;
}
