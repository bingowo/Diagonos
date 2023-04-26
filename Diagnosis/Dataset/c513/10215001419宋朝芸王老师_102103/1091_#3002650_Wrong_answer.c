#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define M 1000002

//0 1 -1
//i -i
//bi -bi
//a+i a-i
//a+bi a-bi //-a+bi -a-bi

typedef struct{
    int v[M];
    int len;
    int flag;
}BIG;

typedef struct{
    BIG rez;
    BIG imz;
}COM;

BIG st(BIG a){  //copy
    BIG res = {{0},0,0};
    res.flag = a.flag;
    res.len = a.len;
    for(int i = 0; i < a.len; i++) res.v[i] = a.v[i];
    return res;
}

BIG re_st(BIG a){   //reverse copy
    BIG res = {{0},0,0};
    res.flag = a.flag;
    res.len = a.len;
    for(int i = 0; i < a.len; i++) res.v[i] = a.v[a.len - 1 - i];
    return res;
}

COM put(char *s, int len){  //convert s into com
    COM res = {{{0},0,0,},{{0},0,0}};
    BIG temp = {{0},0,0};
    int i = 0;

    if(len == 1 && s[0] == '0'){res.rez.len = 1;return res;}  //0
    if(len == 1 && s[0] == 'i'){res.imz.len = 1;res.imz.flag = 1;res.imz.v[0] = 1;return res;}  //i

    temp.flag = 1;
    if(s[i] == '-') {temp.flag = -1;i++;}
    if(s[i] == 'i') {res.imz.len = 1;res.imz.flag = -1;res.imz.v[0] = 1; return res;} //-i
    while(isdigit(s[i])) {temp.v[temp.len++] = s[i] - '0';i++;}   //remember to reverse!
    if(s[i] == 'i') {res.imz = re_st(temp);return res;}    //ai -ai
    res.rez = re_st(temp);  //(1 -1)
    if(i == len) return res;    //1 -1

    temp.flag = -1; temp.len = 0;
    if(s[i] == '+') temp.flag = 1;
    i++;
    if(s[i] == 'i') {res.imz.len = 1;res.imz.flag = temp.flag;res.imz.v[0] = 1;return res;} //a+i a-i
    while(isdigit(s[i])) {temp.v[temp.len++] = s[i] - '0';i++;}
    res.imz = re_st(temp);
    if(i == len) return res;

    return res;
}

BIG mul(BIG a, BIG b){
    BIG res = {{0},0,0};

    //flag
    if(a.flag == 0 || b.flag == 0){res.len = 1; return res;}
    if(a.flag == b.flag) res.flag = 1;
    else res.flag = -1;

    //start mul for v
    for(int m = 0; m < b.len; m++){
        int t,k,n;
        int carry = 0;

        for(n = 0; n < a.len; n++){
            t = a.v[n]*b.v[m] + carry + res.v[n+m];
            res.v[n+m] = t % 10;
            carry = t / 10;
        }
        k = m + n;
        while(carry > 0){
            t = carry + res.v[k];
            res.v[k] = t % 10;
            carry = t / 10;
            k++;
        }
    }

    //len
    res.len = a.len + b.len;
    if(res.v[a.len+b.len-1] == 0) res.len--;
    return res;
}

int cmp(BIG a, BIG b){  //if same, return 0;
//else if a is bigger, return 1; else return -1;
    if(a.flag != b.flag) return a.flag > b.flag ? 1 : -1;
    //same flag
    int ret = 0;
    if(a.len != b.len){
        ret =  a.len > b.len ? 1 : -1;
        if(a.flag == -1) ret = -ret;
        return ret;
    }
    //same len
    for(int i = a.len - 1; i >= 0; i--){
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
    if(y.flag == 0) return x;
    if(x.flag == 0) {y.flag = -y.flag;return y;}

    BIG a = {{0},0,0}, b = {{0},0,0}, res = {{0},0,0};
    if(cmp(x,y) == 0) {a.len = 1;return a;}
    if(cmp(x,y) == 1) {a = st(x), b = st(y);res.flag = 1;}
    else {a = st(y), b = st(x);res.flag = -1;}

    //a-b
    //if(b.flag == 0) {a.flag = res.flag;return a;}
    //if(a.flag == 0){b.flag = -res.flag;return b;}

    if(b.flag == a.flag && a.flag == 1){    //a-b //positive - positive
        int t,carry = 0;
        for(int i = 0; i < max(a.len,b.len); i++){
            if(a.v[i] < b.v[i]){
                carry = 1;
                a.v[i+1]--;
            }
            t = a.v[i] - b.v[i] + 10*carry;
            res.v[res.len++] = t;
            carry = 0;
        }
        if(res.v[res.len-1] == 0) res.len--;
        return res;
    }

    else if(a.flag == b.flag){  //negtive - negtive
        a.flag = 1, b.flag = 1;
        res = minus(b,a);
        return res;
    }

    //a- -b (ignore flag)   //positive - negtive
    int t,carry = 0;
    for(int i = 0; i < max(a.len,b.len); i++){
        t = a.v[i] + b.v[i] + carry;
        res.v[res.len++] = t%10;
        carry = t/10;
    }
    if(carry > 0){
        res.v[res.len++] = carry;
    }

    return res;
}

COM mul_C(COM a, COM b){
    COM res = {{{0},0,0,},{{0},0,0}};
    BIG t1 = {{0},0,0}, t2 = {{0},0,0};

    //if(a.imz.flag != 0 && b.imz.flag != 0 && a.rez.flag != 0 && b.rez.flag != 0)
    t1 = mul(a.rez,b.rez), t2 = mul(a.imz,b.imz);
    res.rez = minus(t1,t2);

    t1 = mul(a.rez,b.imz), t2 = mul(a.imz,b.rez);
    t2.flag = - t2.flag;
    res.imz = minus(t1,t2);

    return res;
}

COM cal(COM a, int n){  //cal a^n
    COM res = {{{0},0,0,},{{0},0,0}};
    if(a.imz.flag == 0 && a.rez.flag == 0) {res.rez.len = 1;res.rez.v[0] = 1;res.rez.flag = 1;return res;}
    if(n == 0) {
        res.rez.v[res.rez.len++] = 1;
        res.rez.flag = 1;
        return res;
    }
    if(n == 1) return a;
    if(a.imz.flag == 0 && a.rez.len == 1 && a.rez.v[0] == 1){
        res.rez.len = 1;res.rez.v[0] = 1;
        if(a.rez.flag == 1 || n%2 == 0){res.rez.flag = 1;}
        else res.rez.flag = -1;
        return res;
    }

    res = cal(a,n/2);
    res = mul_C(res,res);
    if(n%2 == 1) res = mul_C(res,a);

    return res;
}

void output(COM res){
    if(res.imz.flag == 0){    //0 -1
        if(res.rez.flag == -1) printf("-");
        for(int i = res.rez.len -1; i >= 0; i--) printf("%d",res.rez.v[i]);
        return;
    }
    if(res.rez.flag == 0 && res.imz.len == 1 && res.imz.v[0] == 1){ //i -i
        if(res.imz.flag == -1) printf("-");
        printf("i");
        return;
    }
    if(res.rez.flag == 0){    //bi -bi
        if(res.imz.flag == -1) printf("-");

        for(int i = res.imz.len - 1; i >= 0; i--) printf("%d",res.imz.v[i]);
        printf("i");
        return;
    }
    if(res.imz.len == 1 && res.imz.v[0] == 1){    //a+i -a-i
        if(res.rez.flag == -1) printf("-");
        for(int i = res.rez.len -1; i >= 0; i--) printf("%d",res.rez.v[i]);

        if(res.imz.flag == -1) printf("-");
        else printf("+");
        printf("i");
        return;
    }
    else{   //a+bi a-bi //-a+bi -a-bi
        if(res.rez.flag == -1) printf("-");
        for(int i = res.rez.len -1; i >= 0; i--) printf("%d",res.rez.v[i]);

        if(res.imz.flag == -1) printf("-");
        else printf("+");
        for(int i = res.imz.len - 1; i >= 0; i--) printf("%d",res.imz.v[i]);
        printf("i");
        return;
    }
}

int main()
{
    COM com = {{{0},0,0,},{{0},0,0}}, res = {{{0},0,0,},{{0},0,0}};
    char s[2*M+2] = {'\0'};
    int n;
    scanf("%s%d",s,&n);

    com = put(s, strlen(s));
    res = cal(com,n);

    output(res);
    return 0;
}
