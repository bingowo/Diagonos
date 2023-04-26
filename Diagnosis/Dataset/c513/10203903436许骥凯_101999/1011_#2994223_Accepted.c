#include<stdio.h>
#include<string.h>
#define ll long long

int main(){
    char s[1000]; scanf("%s", s); int slen = strlen(s);
    int res[1000], rlen = (slen - 2) * 4;
    for (int i = 2; i != slen; i++){
        int temp = s[i] >= 'A'? s[i] - 'A' + 10: s[i] - '0';
        for (int j = 0; j != 4; j++){
            res[4 * (i - 1) - j - 1] = temp % 2;
            temp /= 2;
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
        if (b == 1) printf("i\n");
        else if (b == -1) printf("-i\n");
        else printf("%lldi\n", b);
    }
}