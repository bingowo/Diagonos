#include <bits/stdc++.h>
using namespace std;
bool cmp1(string s1, string s2){
    int flag1=1, flag2=1, zhengshu1[110], zhengshu2[110], len1=0, len2=0;
    memset(zhengshu1, -1, sizeof(zhengshu1));
    memset(zhengshu2, -1, sizeof(zhengshu2));
    if(s1[0]=='-') flag1 = -1; //比大小
    if(s2[0]=='-') flag2 = -1;
    if(flag1==-1 && flag2==1) return 1;
    else if(flag1==1 && flag2==-1) return 0;
    int len;
    string::size_type idx = s1.find('.'); 
    if(idx == string::npos) //读整数1
        len = s1.size();
    else
        len = idx;
    for(int i=0; i<len && i<100; i++){//
        if(s1[i]>='0' && s1[i]<='9')
            zhengshu1[len1++] = s1[i]-48;
    }
    idx = s2.find('.');
    if(idx == string::npos) //读整数2
        len = s1.size();
    else
        len = idx;
    for(int i=0; i<len && i<100; i++){//
        if(s2[i]>='0' && s2[i]<='9')
            zhengshu2[len2++] = s2[i]-48;
    }
    if(len1>len2){ //比大小
        if(flag1==1) return 0;
        else return 1; 
    }else if(len1<len2){
        if(flag1==1) return 1;
        else return 0; 
    }else{
        for(int i=0; i<len1; i++){
            if(zhengshu1[i]>zhengshu2[i]){
                if(flag1==1) return 0;
                else return 1;
            }else if(zhengshu1[i]<zhengshu2[i]){
                if(flag1==1) return 1;
                else return 0;
            }
        }
    }
    int xiaoshu1[110], xiaoshu2[110], len3=0, len4=0;
    memset(xiaoshu1, -1, sizeof(xiaoshu1));
    memset(xiaoshu2, -1, sizeof(xiaoshu2));
    idx = s1.find('.');
    if(idx!=string::npos){ //读小数1
        for(int i=idx+1; i<s1.size(); i++){
            if(s1[i]>='0' && s1[i]<='9')
                xiaoshu1[len3++] = s1[i]-48;
        }
    }
    idx = s2.find('.');
    if(idx!=string::npos){ //读小数2
        for(int i=idx+1; i<s2.size(); i++){
            if(s2[i]>='0' && s2[i]<='9')
                xiaoshu2[len4++] = s2[i]-48;
        }
    }
    len = (len3>len4)? len3: len4;
    for(int i=0; i<len&& i<100; i++){  //比大小
        if(xiaoshu1[i]>xiaoshu2[i]){
            if(flag1==1) return 0;
            else return 1;
        }else if(xiaoshu1[i]<xiaoshu2[i]){
            if(flag1==1) return 1;
            else return 0;
        }
    }
    return 0;
}
int main(){
    int n;
    cin>> n;
    vector<string> s;
    string s1;
    for(int i=0; i<n; i++){
        cin>> s1;
        s.push_back(s1);
    }  
    sort(s.begin(), s.end(), cmp1);
    for(int i=0; i<n; i++){
        cout<< *s.begin()<< endl;
        s.erase(s.begin());
    }
    return 0;
}