#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 500

typedef struct{
    int v[M];
    int cnt;
    int flag;
}BIG;

BIG int2big(int a){
    BIG c;
    int i = 0;
    while(a > 0){
        c.v[i++] = a%10;
        a = a/10;
    }
    c.flag = 1;
    c.cnt = i;
    return c;
}

BIG add(BIG a, BIG b){
    BIG c;

    int carry = 0, i;
    for(i = 0; i < a.cnt || i < b.cnt; i++){
        int temp = a.v[i] + b.v[i] + carry;
        carry = temp/10;
        c.v[i] = temp%10;
    }
    if(carry > 0) c.v[i++] = carry;
    c.cnt = i;
    c.flag = 1;
    return c;
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
        while(res.v[res.cnt-1] == 0) res.cnt--;
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

BIG process(BIG a){
    BIG res;
    if(a.cnt == 1 && a.v[0] == 1) return int2big(1);
    if(a.cnt == 1 && a.v[0] == 2) return int2big(2);
    if(a.cnt == 1 && a.v[0] == 3) return int2big(3);
    if(a.cnt == 1 && a.v[0] == 4) return int2big(6);
    else{
        res = process(minus(a,int2big(1)));
        res = add(res,process(minus(a,int2big(2))));
        res = add(res,process(minus(a,int2big(4))));
    }
    return res;
}

int main()
{
    BIG res[502];
    res[0] = int2big(0); res[1] = int2big(1); res[2] = int2big(2);
    res[3] = int2big(3); res[4] = int2big(6);
    for(int i = 5; i <= 501; i++){
        res[i] = add(res[i-1],res[i-2]);
        res[i] = add(res[i],res[i-4]);
    }

    int n;
    scanf("%d",&n);

    //BIG a = process(int2big(n));
    for(int i = res[n].cnt-1; i >= 0; i--)
        printf("%d",res[n].v[i]);

    return 0;
}
