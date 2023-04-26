#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s, t;
	int i, len;
	cin >> s;
	len = s.length(), t = s;
	for (i = 0; i < len; i++) {
		t = s;
		t.insert(i, 1, s[i]);
		if (t < s) {
			len++, i++;
			s = t;
		}
	}
	cout << s << endl;
	return 0;
}
