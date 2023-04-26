#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
string addOne(string a) {
    string ans;
    int sum, carry = 1;
    for (int i = a.size() - 1; i >= 0; --i) {
        sum = a[i] - '0' + carry;
        carry = sum / 10;
        ans.insert(0, 1, sum % 10 + '0');
    }
    if (carry != 0) {
        ans.insert(0, 1, carry + '0');
    }
    return ans;
}
bool lesser(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    } else {
        return a.size() < b.size();
    }
}
string solve(string str) {
    if (str.size() == 1) {
        return str;
    }
    string sub = str.substr(0, str.size() - 1);
    string temp = solve(sub);
    if (lesser(sub, temp)) {
        str = temp.append(1, '0');
    }
    if (str[str.size() - 1] == str[str.size() - 2]) {
        temp = addOne(str);
        return solve(temp);
    }
    return str;
}
int main() {
    int t;
    cin >> t;
    string str;
    for (int cas = 0; cas < t; ++cas) {
        cin >> str;
        str = addOne(str);
        str = solve(str);
        printf("case #%d:\n%s\n", cas, str.c_str());
    }
    return 0;
}