#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,k=0;cin>>t;
    while(t--){
        cout<<"case #"<<k++<<":\n";
        set<char>S;
        vector<char>str;
        vector<string>out;
        string s;cin>>s;
        for(int i=0;i<s.size();i++) S.insert(s[i]);
        for(set<char>::iterator it=S.begin();it!=S.end();it++){
            str.push_back(*it);
        }
        for(int i=0;i<(1<<(str.size()));i++){
            string ss="";
            for(int j=0;j<str.size();j++){
                if(i&(1<<j)) ss+=str[j]; 
            }
            if(ss!="")
                out.push_back(ss);
        }
        sort(out.begin(),out.end());
        for(int i=0;i<out.size();i++) cout<<out[i]<<endl;
    }
}