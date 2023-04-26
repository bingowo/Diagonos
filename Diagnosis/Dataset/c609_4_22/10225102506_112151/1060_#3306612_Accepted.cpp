#include <iostream>
#include <string>

using namespace std;

int Xiaoyu(string s,int x){
    int i=0;
    while(s[i+x]){
        if(s[i+x]!=s[i+x+1]&&s[i+x+1])
            break;
        if(s[i+x+1]=='\0')
            break;
        i++;
    }
    if(s[i+x]<s[i+x+1]&&s[i+x+1]) return 1;
    return 0;
}

int main()
{
    string s,t;
    cin >> s;
    for(string::iterator it=s.begin();it!=s.end();++it){
        t+=*it;
        if(*it<*(it+1)&&*(it+1))
            t+=*it;
        if(*it==*(it+1)&&Xiaoyu(s,it+1-s.begin())&&*(it+2))
            t+=*it;
    }
    cout << t <<endl;
    return 0;
}
