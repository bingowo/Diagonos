#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N{ 100 };
struct T{ string s{ string(N, '0') }, sx{ string(2 * N, '0') }; int sign{}; };
void preprocess(T& p)
{
	string s = p.s;
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			p.sign = 1;
		s.erase(0, 1);
	}
	if (s.find('.') == string::npos)
		s += ".";
	p.sx.replace(N - s, find('.'), s.size(), s);
}
int main()
{
	int i, n; T a[N];
	for (cin >> n, i = 0; i<n&&cin >> a[i].s; i++)
		preprocess(a[i]);
	sort(a, a + n, [](const T e1, const T e2)->bool
	{return (e1.sign != e2.sign) ? e2.sign < e1.sign : (e1.sign == 0) ? e1.sx < e2.sx : e2.sx < e1.sx; });
	for (i = 0; i<n; i++)
		cout << a[i].s << endl;

}