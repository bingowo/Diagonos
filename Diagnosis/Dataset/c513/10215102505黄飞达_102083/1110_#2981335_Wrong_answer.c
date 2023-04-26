#include<stdio.h>
#include<string.h>
#define ll long long

int main(){
    char x;
    char s[85]={};
    gets(s);
    int slen = strlen(s);
    for (int i=0; i<slen; i++){
        if ('a'<=s[i] && s[i]<='z'){
            x = s[i]; 
            break;
        }
    }
    ll num=0, xi=0, temp=0;
    int fuhao=1, pos=0;
    for (int i=0; i<slen; i++){
        if ('0'<=s[i] && s[i]<='9'){
            temp *= 10;
            temp += s[i]-'0';                
        }
        else {
            if (s[i]==x) {
                if (temp==0) temp=1;
                xi += temp;
                temp=0;
            }
            else {
                if (s[i]=='=') {
                    num+=temp*fuhao*(-1);
                    pos=i+1;
                    fuhao=-1;
                    temp=0;
                    break;
                }
                else {
                    num+=temp*fuhao*(-1);
                    fuhao=s[i]=='+'?1:-1;
                    temp=0;
                }
            }
        }
    }
    for (int i=pos; i<slen; i++){
        if ('0'<=s[i] && s[i]<='9'){
            temp *= 10;
            temp += s[i]-'0';                
        }
        else {
            if (s[i]==x) {
                if (temp==0) temp=1;
                xi += temp*fuhao; 
                temp=0;
            }
            else {
                num+=temp*fuhao*(-1);
                fuhao=s[i]=='+'?-1:1;
                temp=0;
            }
        }
    }
    double res = num*1.0/xi;
    if (res<=0 && res>-0.0005) printf("%c=0.000\n", x);
    else printf("%c=%.3lf\n", x, res);
    return 0;
}