#include<iostream>
#include<string>

using namespace std;

int main(){
    string s,t,s2;
    int i,len;
    for(cin>>s,len=s.length(),i=0;i<len;i++)
    {
      t=s;
      s2=s[i];
      if(t.insert(i,s2)<s) len++,i++,s=t;
    }
    cout<<s;
    return 0;
}
