#include <iostream>
#include <cstring>
using namespace std;

#define N 100

string R(string s) { string t; if(!s.empty()) { t = s[0]; t += s[0]; string temp = R(s.substr(1, s.size()-1)); strcpy(&t[2], temp.c_str()); t = t.substr(0, temp.size()+2); if(t < s) { s = t; } } return s; }

int main() { string s; cin >> s; cout << R(s) << endl; return 0; }