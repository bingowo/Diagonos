#include <iostream>
#include <string>
#include <cstring>

#define MAXLEN 100

using namespace std;
char *change(char *ps);

int main()
{
    string s{string(MAXLEN,'0')};
    cin>>s;
    char *ps=&s[0];
    change(ps);
    cout<<ps<<endl;
    return 0;
}

char *change(char *ps)
{
    if(*ps)
    {
        string t{string(2*MAXLEN+1,'0')};
        char *pt=&t[0];
        if(strcmp((*pt=*(pt+1)=*ps,strcpy(pt+2,change(ps+1))-2),ps)<0)strcpy(ps,pt);
    }
    return ps;
}