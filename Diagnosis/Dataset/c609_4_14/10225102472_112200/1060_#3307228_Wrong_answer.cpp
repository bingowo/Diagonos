#include<bits/stdc++.h>
using namespace std;
#define N 100

string R(string s)
{
    string tt;
    tt.push_back(2*N+1);
    //char *t = &tt[0];
    if(s.size())
    {
        if((tt[0]=tt[1]=s[0], tt += R(s.substr(1)))<s)
        {
            s = tt;
        }
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    cout << R(s);
    return 0;
}