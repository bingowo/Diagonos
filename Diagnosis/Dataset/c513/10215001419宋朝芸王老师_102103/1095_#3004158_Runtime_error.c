#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000

typedef struct{
    int v[2*M];
    int cnt;
    int flag;
}BIG;

typedef struct{
    BIG rez;
    BIG imz;
}COM;

int hex2bin(char hex[], int len, int bin[]){
    int lenBin = 0;
    int st = 0;

    for(int i = 0; i < len; i++){
        int temp;
        if(hex[i]>='A') temp = hex[i] - 'A' + 10;
        else temp = hex[i] - '0';

        unsigned int flag = 0x8;
        while(flag){
            if(temp & flag) {
                bin[lenBin++] = 1;
                st = 1;
            }
            else if(st != 0) bin[lenBin++] = 0;
            flag = flag >> 1;
        }
    }
    return lenBin;
}

BIG int2big(int a){
    BIG res = {{0},0,0};
    if(a == 0){
        res.cnt = 1;
        return res;
    }
    res.flag = -1;
    if(a > 0) res.flag = 1;
    if(a < 0) a = -a;
    while(a > 0){
        res.v[res.cnt++] = a%10;
        a = a/10;
    }
    return res;
}

BIG st(BIG a){  //copy
    BIG res = {{0},0,0};
    res.flag = a.flag;
    res.cnt = a.cnt;
    for(int i = 0; i < a.cnt; i++) res.v[i] = a.v[i];
    return res;
}

int cmp(BIG a, BIG b){  //if same, return 0;
//else if a is bigger, return 1; else return -1;
    if(a.flag != b.flag) return a.flag > b.flag ? 1 : -1;
    //same flag
    int ret = 0;
    if(a.cnt != b.cnt){
        ret =  a.cnt > b.cnt ? 1 : -1;
        if(a.flag == -1) ret = -ret;
        return ret;
    }
    //same len
    for(int i = a.cnt - 1; i >= 0; i--){
        if(a.v[i] != b.v[i]){
            ret = a.v[i] > b.v[i] ? 1 : -1;
            break;
        }
    }
    if(a.flag == -1) ret = -ret;
    return ret;
}

int max(int a, int b){
    return a > b ? a : b;
}

BIG minus(BIG x,BIG y){
    int ff;
    if(y.flag == 0) return x;
    if(x.flag == 0) {y.flag = -y.flag;return y;}

    BIG a = {{0},0,0}, b = {{0},0,0}, res = {{0},0,0};
    if(cmp(x,y) == 0) {a.cnt = 1;return a;}
    if(cmp(x,y) == 1) {a = st(x), b = st(y);res.flag = 1;ff = res.flag;}
    else {a = st(y), b = st(x);res.flag = -1;ff = res.flag;}

    //a-b
    //if(b.flag == 0) {a.flag = res.flag;return a;}
    //if(a.flag == 0){b.flag = -res.flag;return b;}

    if(b.flag == a.flag && a.flag == 1){    //a-b //positive - positive
        int t,carry = 0;
        for(int i = 0; i < max(a.cnt,b.cnt); i++){
            if(a.v[i] < b.v[i]){
                carry = 1;
                a.v[i+1]--;
            }
            t = a.v[i] - b.v[i] + 10*carry;
            res.v[res.cnt++] = t;
            carry = 0;
        }
        if(res.v[res.cnt-1] == 0) res.cnt--;
        return res;
    }

    else if(a.flag == b.flag){  //negtive - negtive
        a.flag = 1, b.flag = 1;
        res = minus(b,a);
        res.flag = ff;
        return res;
    }

    //a- -b (ignore flag)   //positive - negtive
    int t,carry = 0;
    for(int i = 0; i < max(a.cnt,b.cnt); i++){
        t = a.v[i] + b.v[i] + carry;
        res.v[res.cnt++] = t%10;
        carry = t/10;
    }
    if(carry > 0){
        res.v[res.cnt++] = carry;
    }

    return res;
}

COM bin2com(int bin[], int lenBin){
    BIG qr = {{0},1,0}, qi = {{0},1,0},
        a = {{0},0,0},  b = {{0},0,0},
        r = {{0},0,0};

    for(int i = 0; i < lenBin; i++){
        r = int2big(bin[i]);
        a = minus(r,qr);
        a = minus(a,qi);
        b = minus(qr,qi);
        qr = st(a);
        qi = st(b);
    }

    if(qr.flag != 0){
        while(qr.v[qr.cnt-1] == 0) qr.cnt--;
    }
    if(qi.flag != 0){
        while(qi.v[qi.cnt-1] == 0) qi.cnt--;
    }

    COM res = {{{0},0,0},{{0},0,0}};
    res.rez = st(qr), res.imz = st(qi);

    return res;
}

void output(COM res){
    if(res.imz.flag == 0){    //0 -1
        if(res.rez.flag == -1) printf("-");
        for(int i = res.rez.cnt -1; i >= 0; i--) printf("%d",res.rez.v[i]);
        return;
    }
    if(res.rez.flag == 0 && res.imz.cnt == 1 && res.imz.v[0] == 1){ //i -i
        if(res.imz.flag == -1) printf("-");
        printf("i");
        return;
    }
    if(res.rez.flag == 0){    //bi -bi
        if(res.imz.flag == -1) printf("-");

        for(int i = res.imz.cnt - 1; i >= 0; i--) printf("%d",res.imz.v[i]);
        printf("i");
        return;
    }
    if(res.imz.cnt == 1 && res.imz.v[0] == 1){    //a+i -a-i
        if(res.rez.flag == -1) printf("-");
        for(int i = res.rez.cnt -1; i >= 0; i--) printf("%d",res.rez.v[i]);

        if(res.imz.flag == -1) printf("-");
        else printf("+");
        printf("i");
        return;
    }
    else{   //a+bi a-bi //-a+bi -a-bi
        if(res.rez.flag == -1) printf("-");
        for(int i = res.rez.cnt -1; i >= 0; i--) printf("%d",res.rez.v[i]);

        if(res.imz.flag == -1) printf("-");
        else printf("+");
        for(int i = res.imz.cnt - 1; i >= 0; i--) printf("%d",res.imz.v[i]);
        printf("i");
        return;
    }
}


int main()
{
    char s[2*M] = {'\0'};
    scanf("0x%s",s);

    int bin[6*M] = {0};
    int lenBin = hex2bin(s,strlen(s),bin);   //hex 2 bin

    COM res = {{{0},0,0},{{0},0,0}};
    res = bin2com(bin,lenBin); //bin 2 com
    output(res);   //output com

    return 0;
}
