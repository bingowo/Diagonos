#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string a, const string b) {
	bool sign1 = 1, sign2 = 1;
	string s1=a,s2=b;
	int i1 = 0, i2 = 0;
	if (s1[i1] == '-')
		sign1 = 0, i1++;
	else if (s1[i1] == '+'){
		i1++;s1.erase(0,1);}
	if (s2[i2] == '-')
		sign2 = 0, i2++;
	else if (s2[i2] == '+'){
		i2++;s2.erase(0,1);}
	if (sign1 != sign2)
		return sign1 < sign2;
	int p1, p2;
	for (p1 = i1; s1[p1] && s1[p1] != '.'; p1++);
	for (p2 = i2; s2[p2] && s2[p2] != '.'; p2++);
	int len1 = p1 - i1, len2 = p2 - i2;
	if (len1 < len2)
		return sign1;
    else return !sign1;
	return (sign1==0?-1:1) * s1.compare(s2)>0;
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
