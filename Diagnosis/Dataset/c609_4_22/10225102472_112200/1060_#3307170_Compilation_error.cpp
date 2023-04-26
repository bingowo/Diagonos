#include<bits/stdc++.h>
using namespace std;
#define N 100

char *R(char *s)
{
    string t;
    int i = 0;
    if(*s)
    {
        if(strcmp((t[i]=t[i+1]=*s, strcpy(t+2, R(s+1))-2), s)<0)
        {
            strcpy(s, t);
        }
    }
    return s;
}

int main()
{
    char s[2*N+1];
    cin >> s;
    cout << R(s);
    return 0;
}