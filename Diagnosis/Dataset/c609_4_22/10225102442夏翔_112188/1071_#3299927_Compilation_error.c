#include <bits/stdc++.h>
using namespace std;
int pow2(int n){
    if(n==0) return 1;
    return 2*pow2(n-1);
}
int main(){
    long long x, y;
    cin>> x>> y;
    int temp=abs(x)+abs(y);
    bool flag=false;
    for(int i=1; i<=40; i++){
        int ret=pow2(i);
        if(ret-1-temp<0) continue;
        if((ret-1-temp)%2==0){
            cout<< i<< endl;
            flag = true;
            break;
        }
    }
    if(flag==false) cout<< -1<< endl;
    return 0;
}