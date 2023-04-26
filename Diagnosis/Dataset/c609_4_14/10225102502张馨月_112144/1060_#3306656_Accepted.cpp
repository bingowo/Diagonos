#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int N=100;

char* insert(char*s, int pos)
{
    int i;//双倍复制pos位置的字母
    for(i=strlen(s)+1;i>pos;i--)
        s[i]=s[i-1];
    return s;
}
int main()
{
    char s[2*N+1],t[2*N+1];
    int i,len;
    for(cin>>s,len=strlen(s),i=0;i<len;i++)
        if(strcmp(insert(strcpy(t,s),i),s)<0)
        {len++;i++;strcpy(s,t);}
    cout << s << endl;
    return 0;
}
