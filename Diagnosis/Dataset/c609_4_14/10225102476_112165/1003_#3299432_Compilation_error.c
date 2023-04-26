#include <algorithm.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    vector<int> res;
    int n, i;
    long long a;
    int b;
    unsigned int c;

    cin >> n;
    for (i = 0;i < n;i++) {
        res.clear();
        cin >> a;
        while (a >= 2333) {
            b = a % 2333;
            a = a / 2333;
            res.push_back(b);
        }
        res.push_back((int)a);
        for (c = res.size() - 1;c > 0;c--)
            cout << res[c] << ' ';
        cout << res[c] << endl;
    }
}