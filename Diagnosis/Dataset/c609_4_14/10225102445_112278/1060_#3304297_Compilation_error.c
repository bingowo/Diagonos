#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string myMin(string a, string b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

string solve(string s) {
    if (s.size() == 1) return s;
    string res = "";
    string sub = solve(s.substr(1));

    res = myMin(s.substr(0,1) + sub, s.substr(0,1)+ s.substr(0,1) + sub);
    return res;
}
int main()
{ string s;
 cin >> s;

  cout <<solve(s)<< endl;
  return 0;


}
