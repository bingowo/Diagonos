#include<stdio.h>
#include<string.h>

int HexToB(char *s, int *res){
    int slen = strlen(s); int rlen = 0;
    for (int i = 2; i != slen; ++i, rlen += 4){
        int temp = (s[i] >= 'A'? s[i] - 'A' + 10: s[i] - '0');
        for (int j = 3; j >= 0; --j){
            res[rlen + j] = temp % 2;
            temp /= 2;
        }
    }
    return rlen;
}

int main(){
    char s[1000]; scanf("%s", s);
    int bin[5000]; int blen = HexToB(s, bin);

    long long a = 0, b = 0, qi = 0, qr = 0;
    for (int i = 0; i != blen; ++i){
        a = bin[i] - qr - qi;
        b = qr - qi;
        qr = a; qi = b;
    }
    if (b == 0) printf("%lld\n", a);
    else{
        if (a != 0){
            printf("%lld", a);
            if (b > 0) printf("+");
        }
        if (b != 1 && b != -1) printf("%lld", b);
        else if (b == -1) printf("-");
        printf("i\n"); 
    } 
    return 0;
}   