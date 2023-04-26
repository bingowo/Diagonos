#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string a, const string b) {
	int sign1 = 1, sign2 = 1;
	int i1 = 0, i2 = 0;
	string s1=a,s2=b;
	if (s1[i1] == '-')
		sign1 = -1, i1++;
	else if (s1[i1] == '+')
		i1++;
	if (s2[i2] == '-')
		sign2 = -1, i2++;
	else if (s2[i2] == '+')
		i2++;
	if (sign1 != sign2)
		return sign1 < sign2;
	int len1,len2;
    if(s1[0] == '-'||s1[0] == '+')s1.erase(0,1);
    if(s2[0] == '-'||s2[0] == '+')s2.erase(0,1);
    if(s1.find('.')!=string::npos)
        len1=s1.find('.');
    if(s2.find('.')!=string::npos)
        len2=s2.find('.');
	if (len1 < len2)
		return sign1==1;
    else if(len1>len2)
        return sign1==-1;
	return sign1 * s1.compare(s2)>0;
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
