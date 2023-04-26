#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    char c;
    cin>>c;
    vector<int> n;
    int a;
    while(cin>>a){
        n.push_back(a);
    }
    if(c=='A')sort(n.begin(),n.end());
    else sort(n.begin(),n.end(),cmp);
    cout<<n[0]<<' ';
    for(int i=1;i!=n.size();i++){
        if(n[i]!=n[i-1])cout<<n[i]<<' ';}
    return 0;}