#include <string.h>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <tuple>

using namespace std;

void solve();

int main() {
    int t;
    cin >> t;
    for (int i = 0; i != t; ++i) {
        cout << "case #" << i << ":\n";
        solve();
    }
}

void solve() {
    static double frequencies[26];
    for (auto &f : frequencies) {
        cin >> f;
    }

    static char str[101];
    cin >> str;

    // 1. 频率大的在前面；如果相等，
        // 2. 字母序排列；如果相等，
        // 3. 小写在前面。由于 ASCII 里面小写在后面，所以反过来。
    sort(str, str + strlen(str), [](char lhs, char rhs) {
        auto lhs_lower = tolower(lhs);
        auto rhs_lower = tolower(rhs);
        return tie(frequencies[rhs_lower - 'a'], lhs_lower, rhs) <
               tie(frequencies[lhs_lower - 'a'], rhs_lower, lhs);
    });

    cout << str << '\n';
}