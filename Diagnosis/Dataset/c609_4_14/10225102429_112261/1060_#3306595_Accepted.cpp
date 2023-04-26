#include <iostream>
#include <string>
int main(){
    using namespace std;
    string s{},ans{};
    cin>>s;
    int len = s.length();
    int k = 0;
    for(int i = 0; i<len; i++){
        if(i!=len-1){
            if(s[i]<s[i+1]){
                ans+=s[i];
                ans+=s[i];
            }
            else if(s[i]>s[i+1]) ans+=s[i];
            else{
                bool ret = true;
                int j = i+1;
                for(; j<len; j++){
                    if(s[j]<s[i]){
                        ret = false;//复制一次
                        break;
                    }
                    else if(s[j]>s[i]) break;//复制两次
                    else if(j==len-1) ret = false;//复制一次
                }
                if(ret){
                    while(i<j){
                        ans+=s[i];
                        ans+=s[i++];
                    }
                }
                else{
                    while(i<j){
                        ans+=s[i++];
                    }
                }
                i--;
            }
        }
        else ans+=s[i];
    }
    cout<<ans;
    return 0;
}