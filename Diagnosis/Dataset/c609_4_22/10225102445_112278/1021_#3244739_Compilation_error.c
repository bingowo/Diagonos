#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

string arr[1000];
string order;

bool cmp(string a, string b)
{
	for (int i = 0; i < min(a.length(), b.length()); i++)
	{
		char ch1 = toupper(a[i]);
		char ch2 = toupper(b[i]);
		if (order.find(ch1) == order.find(ch2)) continue;
		return order.find(ch1) < order.find(ch2);
	}
	return a.length() < b.length();
}

int main()
{
	string s;
	while (cin >> order)
	{
		getchar();
		getline(cin, s);
		istringstream ss(s);
		int cnt = 0;
		while (ss >> arr[cnt]) cnt++;
		sort(arr, arr + cnt, cmp);
		for (int i = 0; i < cnt; i++)
		{
			cout << arr[i];
			if (i != cnt - 1) cout << " ";
			else cout << endl;
		}
	}
	return 0;
}