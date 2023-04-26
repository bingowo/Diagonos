#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int HexToB(char *s, int *res, int *table){
    int slen = strlen(s); int rlen = 0;
    for (int i = 2; i != slen; ++i, rlen += 4){
        int temp = table[s[i]];
        for (int j = 3; j >= 0; --j){
            res[rlen + j] = temp % 2;
            temp /= 2;
        }
    }
    return rlen;
}

void Init(int *table){
    int n = 0;
    for (int i = '0'; i <= '9'; ++i)
        table[i] = n++;
    for (int i = 'A'; i <= 'F'; ++i)
        table[i] = n++;
}

int main(){
    char s[1000]; scanf("%s", s);

    int table[128]; Init(table);
    int bin[5000]; int blen = HexToB(s, bin, table);

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