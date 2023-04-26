#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int N{100};
struct T
{
    string s{string(N, '0')}, sx{string(2 * N, '0')};
    int sign{};
};

void preprocess(T &p)
{
    string s =p.s;
    if (s[0] == '-' || s[0] == '+'){
        if (s[0] == '-') p.sign = 1;
        s.erase(0, 1);
    }
    if(s.find('.') == string::npos) s += '.';
    p.sx.replace(N - s.find('.'), s.size(), s);
}

int main()
{
    int n;
    vector<T> a((cin >> n, n));
    for (auto & e : a) cin >> e.s, preprocess(e);
    sort(a.begin(), a.end(), [](const T e1, const T e2)->bool{
        return (e1.sign != e2.sign) ? e2.sign < e1.sign : (e1.sign == 0) ? e1.sx < e2.sx : e2.sx < e1.sx;
    });
    for (const auto &e : a) cout << e.s << endl;
    return 0;
}