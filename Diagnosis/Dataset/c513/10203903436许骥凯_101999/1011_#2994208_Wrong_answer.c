#include<stdio.h>
#include<string.h>
#define ll long long

int main(){
    char s[1000]; scanf("%s", s); int slen = strlen(s);
    int res[1000]; int rlen = 0;
    for (int i = 2; i != slen; i++){
        int temp = s[i] >= 'A'? s[i] - 'A' + 10: s[i] - '0';
        int flag = 0x8;
        while(flag){
            res[rlen++] = (flag & temp)? 1: 0;
            flag >>= 1;
        } 
    }

    ll qr = 0, qi = 0, a = 0, b = 0;
    for (int i = 0; i != rlen; i++){
        a = res[i] - qr - qi;
        b = qr - qi;
        qr = a; qi = b;
    }

    if (b == 0) printf("%lld\n", a);
    else{
        if (a != 0){
            printf("%lld", a);
            if (b > 0) printf("+");
        }
        printf("%lldi\n", b);
    }
    return 0;
}