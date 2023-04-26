#include <iostream>
#include <string>
using namespace std;

string R(string s)
{ string t{s[0]};
   if (s!="") if ((t+=s[0]+R(s.substr(1,s.length()-1)))<s) s=t;
   return s;
}

int main() { string s;  cout << (cin>>s,R(s)) << endl;  return 0; }