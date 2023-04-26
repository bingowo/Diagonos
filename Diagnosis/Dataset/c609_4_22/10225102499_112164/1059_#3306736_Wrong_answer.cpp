#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string s1, const string s2) {
	int sign1 = 1, sign2 = 1;
	int i1 = 0, i2 = 0;
	if (s1[i1] == '-')
		sign1 = 0, i1++;
	else if (s1[i1] == '+')
		i1++;
	if (s2[i2] == '-')
		sign2 = 0, i2++;
	else if (s2[i2] == '+')
		i2++;
	if (sign1 != sign2)
		return sign1 < sign2;
	int p1, p2;
	for (p1 = i1; s1[p1] && s1[p1] != '.'; p1++);
	for (p2 = i2; s2[p2] && s2[p2] != '.'; p2++);
	int len1 = p1 - i1, len2 = p2 - i2;
	if (len1 != len2)
		return !(sign1 ^ (len1 < len2));
	return !sign1 * (s1.compare(s2));
}

int main() {
	int n;
	string t;
	vector<string>s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		s.push_back(t);
	}
	sort(s.begin(), s.end(), cmp);
	for (int i = 0; i < n - 1; i++)
		cout << s[i] << endl;
	cout << s[n - 1];
}
