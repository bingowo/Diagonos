#include<bits/stdc++.h>
using namespace std;
#define N 100

string R(string s)
{
    char t[2*N+1];
    if(!s.empty())
    {
        if(strcmp((t[0]=t[1]=s[0], strcpy(t+2, R(s.substr(1)).c_str())-2), s.c_str()) < 0)
        {
            s = t;
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