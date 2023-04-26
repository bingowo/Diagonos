#include <bits/stdc++.h>
using namespace std;
void add1(int* num, int len1, int& pos){ //数值上+1
    int temp=1, ret=len1-1;
    while(temp!=0){
        num[ret] += temp;
        temp = num[ret]/10;
        num[ret--] %= 10;
    }
    if(ret<pos) pos = ret;
}
void divide2(int *num, int len1, int& pos){  //除2
    int temp=num[pos], ret;
    while(temp<2){
        num[pos++] = 0;
        if(pos==len1) return;
        temp = temp*10+num[pos];
    }
    ret = pos;
    while(ret<len1){
        num[ret++] = temp/2;
        temp %= 2;
        while(temp<2 && ret<len1){
            temp = temp*10+num[ret];
            num[ret++] = 0;
        }
        if(temp>=2) ret--;
    }
}
void print(int* ans, int len2){  //输出
    for(int i=0; i<len2; i++) cout<< ans[len2-1-i];
}
int main(){
    string s;
    cin>> s;
    int num[1100], flag=1, len1, pos=0, ans[1100], len2=0;
    memset(num, 0, sizeof(num));
    memset(ans, 0, sizeof(ans));
    len1 = s.size();
    if(s[0]=='-'){
        flag = -1;
        pos++;
    }
    for(int i=pos; i<len1; i++){
        num[i] = (int)s[i]-48;
    }
    while(pos<len1){
        if(num[len1-1]%2==1) ans[len2++] = 1;
        else ans[len2++] = 0;
        if(flag==-1) add1(num, len1, pos); //若除数为负数，数值上加1；
        divide2(num, len1, pos);
        flag *= -1;
    }
    print(ans, len2);
    return 0;
}