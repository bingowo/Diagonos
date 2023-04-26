#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

set<string> an,sa;

using q=vector<char>::iterator;

void get(q a,q b){
    q x=a;
    x++;
    
    if(x==b){
        an.insert(string(1,*a));
        return;
    }get(x,b);
    sa.clear();
    for(set<string>::iterator p=an.begin();p!=an.end();p++)sa.insert(string(1,*a)+*p);
     an.insert(sa.begin(),sa.end());
     an.insert(string(1,*a));
}

int main(){
    int n;
    cin>>n;getchar();
    for(int w=0;w<n;w++){
        an.clear();
        char s[16];
        scanf("%s",s);
        vector<char> c(16);
        vector<char>::iterator e;
        sort(s,s+strlen(s));
        e=unique_copy(s,s+strlen(s),c.begin());
        c.resize(e-c.begin());
        get(c.begin(),c.end());
        cout<<"case #"<<w<<":"<<endl;
        for(auto y:an)cout<<y<<endl;
    }
}