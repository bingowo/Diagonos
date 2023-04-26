#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int N{ 100 };

struct T {
    string s{string(N,'0') }, sx{ string(2 * N,'0') };
    int sign{1};
};

void preprocess(T& p)
{
    string s = p.s;
    if (s[0] == '-' || s[0] == '+') {
        if (s[0] == '-') p.sign = -1;
        s.erase(0, 1);
    }
    if (s.find('.') == string::npos) s += ".";
    p.sx.replace(N - s.find('.'), s.size(), s);
}

bool cmp(const T st1,const T st2){
	if (st1.sign!=st2.sign) return st1.sign<st2.sign;
	if (st1.sign==1) return st1.sx<st2.sx;
	else return st1.sx>st2.sx;
}

int main()
{
    int n;
    cin >> n;
    vector<T> a(n);
    for (auto& e : a) cin >> e.s, preprocess(e);
    sort(a.begin(), a.end(), cmp);
    for (auto e : a)cout << e.s << endl;
    return 0;
}