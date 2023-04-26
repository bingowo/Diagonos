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
/*
void StringsplitR(const string &str, const string &split, vector<string> &res)
{
    // std::regex ws_re("\\s+"); // 正则表达式,匹配空格
    regex reg(split); // 匹配split
    sregex_token_iterator pos(str.begin(), str.end(), reg, -1);
    decltype(pos) end; // 自动推导类型
    for (; pos != end; ++pos)
    {
        res.push_back(pos->str());
    }
}
void StringsplitI(string str, const const char split, vector<string> &res)
{
    istringstream iss(str);            // 输入流
    string token;                      // 接收缓冲区
    while (getline(iss, token, split)) // 以split为分隔符
    {
        res.push_back(token); // 输出
    }
}*/
void Stringsplit(const string &str, const char split, vector<string> &res)
{
    if (str == "")
        return;
    // 在字符串末尾也加入分隔符，方便截取最后一段
    string strs = str + split;
    size_t pos = strs.find(split);

    // 若找不到内容则字符串搜索函数返回 npos
    while (pos != strs.npos)
    {
        string temp = strs.substr(0, pos);
        res.push_back(temp);
        // 去掉已分割的字符串,在剩下的字符串中进行分割
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
    if (strList.size() > 1)
    {
        p.integer = strList[0];
        p.fraction = strList[1];
    }
    else
    {
        p.integer = strList[0];
        p.fraction = "0";
    }
    p.int_len = p.integer.length();
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
