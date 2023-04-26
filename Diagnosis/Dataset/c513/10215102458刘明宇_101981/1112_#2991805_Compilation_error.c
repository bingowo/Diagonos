#include <iostream>
using namespace std;
int dp[1111];

int main() {
    int n, t;
    dp[0] = 1;
    int type[4] = {4, 3, 2, 1};
    for (int i = 0; i < 4; i++) {
        for (int j = type[i]; j <= 1000; j++) {
            dp[j] += dp[j - type[i]];
        }
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
