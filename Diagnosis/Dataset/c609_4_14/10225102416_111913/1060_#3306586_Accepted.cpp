#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s; //原字符串
    string t,m;
    int i=0;
    int num=1;
    cin>>s;
    t = s;
    m = s;
    while(num != m.length()){
        s.insert(i,{s[i]});
        if(t<s){
            s = t;
            i = i+1;
            num++;
        }else if(t>s){
            t = s;
            i = i+2;
            num++;
        }
    }
    cout<<s<<endl;
    return 0;
}
