#include <iostream>
#include <cstring>
const int N=100;
char *R(char* s)
{
     char t[2*N+1];
     if (*s) if (strcmp((*t=*(t+1)=*s,strcpy(t+2,R(s+1))-2),s)<0) strcpy(s,t);
     return s;
}
using namespace std;

int main()
{
    char s[2*N+1];
    cin>>s;
    R(s);
    cout<<s<<endl;

    return 0;
}