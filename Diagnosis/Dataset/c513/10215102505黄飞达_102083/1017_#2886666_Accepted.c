#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long

ll arr[128] = {0};
char s[100];
ll i = 0;

ll func(){
    ll res = 0, temp = 0;
    while (i < strlen(s)){
        if (i == strlen(s)-1) {
            //处理最后一位
            if (s[i] != ')') res += arr[s[i]];
            break;
        }
        ll l = arr[s[i]], r = arr[s[i+1]];
        // if (temp != 0) {
        //     l = temp;
        //     temp = 0;
        // }

        if (s[i] == '('){
            i++;
            temp = 1000*func();
            if (l < temp) res -= l;
            else res += l;
        }
        else if (s[i+1] == '('){
            i += 2;
            temp = 1000*func();
            if (l < temp) res -= l;
            else res += l;
        }
        else if (s[i] == ')'){
            i++;
            break;
        }
        else if (l < r) {
            res -= l;
            i++;
        }
        else if (l >= r){
            res += l;
            i++;
        }        
    } 
    if (temp != 0) res += temp;
    return res;
}

int main(){
    arr['I']=1,arr['V']=5,arr['X']=10,arr['L']=50,arr['C']=100,arr['D']=500,arr['M']=1000;
    gets(s);
    ll res = func();
    printf("%lld\n", res);
    return 0;
}
