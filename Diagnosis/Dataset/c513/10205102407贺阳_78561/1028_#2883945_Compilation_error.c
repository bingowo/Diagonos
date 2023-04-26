#include <iostream>
#include <set>
using namespace std;

int main() {
    int temp;
    char c;
    set<int> s;
    cin >> c;
    while (cin >> temp)
        s.insert(temp);
    auto i1 = s.begin();
    auto i2 = s.rbegin();
    if (c == 'A'){
        cout << *(i1++);
        while (i1 != s.end())
            cout << ' ' << *(i1++);
    }
    else {
        cout << *(i2++);
        while (i2 != s.rend())
            cout << ' ' << *(i2++);
    }
    return 0;
}