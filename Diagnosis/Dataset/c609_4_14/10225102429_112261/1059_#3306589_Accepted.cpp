#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string &a, string &b)
{
    int i = 0,j = 0,signa = 1,signb = 1;
    int lena = a.length(),lenb = b.length();
    if(a[i]=='-'||a[i]=='+'){
        if(a[i]=='-') signa = -1;
        i++;
    }
    if(b[j]=='-'||b[j]=='+'){
        if(b[j]=='-') signb = -1;
        j++;
    }
    if(signa!=signb) return signa<signb;
    else{
        int lenInta = i+1,lenIntb = j+1;
        if(signa>0){
            while(lenInta<lena&&a[lenInta]!='.') lenInta++;
            while(lenIntb<lenb&&b[lenIntb]!='.') lenIntb++;
            if(lenInta-i!=lenIntb-j) return lenInta-i<lenIntb-j;
            while(i<lenInta&&a[i]==b[j]) {
                i++;
                j++;
            }
            if(i==lenInta) return a<b;
            return a[i]<b[j];
        }
        else{
            while(lenInta<lena&&a[lenInta]!='.') lenInta++;
            while(lenIntb<lenb&&b[lenIntb]!='.') lenIntb++;
            if(lenInta-i!=lenIntb-j) return lenInta-i>lenIntb-j;
            while(i<lenInta&&a[i]==b[j]) {
                i++;
                j++;
            }
            if(i==lenInta) return a>b;
            return a[i]>b[j];
        }
    }
}
int main(){
    int t;cin>>t;
    vector<string> a(t,"");
    for(int i = 0; i<t; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),cmp);
    for(int i = 0; i<t; i++) cout<<a[i]<<'\n';
    return 0;
}