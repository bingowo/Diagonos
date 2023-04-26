#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main()
{
    int n;
    string str;

    cin >> n;
    while (cin.get() != '\n');

    while (n--) {

        getline(cin, str);
        /*cout << "str = " << str << endl;*/

        int sum = 0;

        for (auto& item : str) {
            auto ptr = new bitset<8>(item);
            sum += ptr->count();
        /*cout << "sum = " << sum << endl;*/

        }

        int g = gcd(sum, str.length() * 8);
        cout << sum / g << '/' << str.length() * 8 / g << endl;

    }

    return 0;

}
