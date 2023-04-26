#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define ll long long

ll myabs(ll num){
    if (num < 0) num = -num;
    return num;
}

ll getValue(char s[]){
    ll res = 0;
    int fuhao = 1, i = 0;
    if (s[0] == '-'){
        fuhao = -1;
        i++;
    }
    else if (s[i] == '+') i++;
    int j;
    for (j = i; j < strlen(s); j++){
        if(isdigit(s[j])){
            res *= 10;
            res += (s[j] - '0'); 
        }
        else break;
    }
    if (res == 0 && s[j] == 'i') res = 1;
    return res*fuhao;
}

int main(){
    ll a, b, c, d;
    int res[200] = {0};
    char s[50];
    gets(s);
    char* sp1 = strchr(s, '+');
    char* sp2 = strchr(s, '-');
    char* sp3 = strchr(s, 'i');
    if (sp3 == NULL) {a = getValue(s); b = 0;}//实数
    else {
        if (sp1 == NULL && sp2 == NULL) {//纯虚数
            a = 0; 
            b = getValue(s);
        }
        else {//非纯虚数
            if (sp1 != NULL){ //存在+号，两侧都有数
                a = getValue(s);
                b = getValue(sp1);
            }
            else { // 不存在+号，两种情况：
                char* sp4 = strchr(sp2+1, '-');
                if (sp4 == NULL){ //一个-号，在两个数之间
                    if (sp2 == s) a = 0;
                    else a = getValue(s);
                    b = getValue(sp2);
                }
                else {// 两个-号，前面一个、中间一个
                    a = getValue(s);
                    b = getValue(sp4);
                } 
            }
        } 
    }
    int r;
    if (myabs(a)%2 == myabs(b)%2) r = 0;
    else r = 1;
    res[0] = r;
    int i;
    for (i = 0; a != 0 || b != 0 ;i++){
        c = (r-a+b)/2;
        d = (r-a-b)/2;
        a = c;
        b = d;
        if (myabs(a)%2 == myabs(b)%2) r = 0;
        else r = 1;
        res[i+1] = r;
    }
    if (i == 0) printf("0");
    else for (int j = i-1; j >= 0; j--) printf("%d", res[j]);
    printf("\n");
    return 0;
}


