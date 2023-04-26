#include<stdio.h>
#include<string.h>
#define ll long long

typedef struct{
    ll r, i;
}Real;

Real trans(const char *s){
    Real res = {0, 0};
    int slen = strlen(s), i = 0, rflag = 0, iflag = 0;
    if (s[0] == '-') rflag = 1, i++;
    for (; i < slen && s[i] != '+' && s[i] != '-' && s[i] != 'i'; i++)
        res.r = res.r * 10 + s[i] - '0';
    
    if (s[i] == '+') i++;
    else if (s[i] == '-') iflag = 1, i++;
    else if (s[i] == 'i'){
        if (res.r == 0) res.r = 1;
        if (rflag) res.r = -res.r;
        res.i = res.r;
        res.r = 0;
        return res;
    }

    for (; i < slen && s[i] != 'i'; i++)
        res.i = res.i * 10 + s[i] - '0';
    
    if (s[i] == 'i' && res.i == 0) res.i = 1;
    if (rflag) res.r = -res.r;
    if (iflag) res.i = -res.i;
    return res;
}

int main(){
    char s[50]; scanf("%s", s);
    Real res = trans(s);
    int bin[1000] = {0}, blen = 0;
    if (res.i == 0 && res.r == 0) blen++;
    while(res.i != 0 || res.r != 0){
        bin[blen] = ((res.r % 2 + 2) % 2) ^ ((res.i % 2 + 2) % 2);
        int a = res.r , b = res.i;
        res.i = (bin[blen++] - a - b) / 2;
        res.r = res.i + b;
    }
    for (int i = blen - 1; i >= 0; i--) printf("%d", bin[i]);
    printf("\n");
    return 0;
}