#include<bits/stdc++.h>
using namespace std;
string R(string s)
{
    string t(2*N+1);
    if(*s)
    {
        if(strcmp((*t=*(t+1)=*s, strcpy(t+2, R(s+1))-2), s)<0)
        {
            strcpy(s, t);
        }
    }
    return s;
}

int main()
{
    char s[2*N+1];
    printf("%s\n", (scanf("%s", s), R(s)));
    return 0;
}