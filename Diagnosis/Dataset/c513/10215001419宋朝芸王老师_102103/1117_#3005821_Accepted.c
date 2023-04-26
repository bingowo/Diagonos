#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 17

typedef struct{
    int v[M+1];
    int cnt;
    int flag;
}BIG;

typedef struct{
    BIG x;
    BIG y;
    BIG dis;
}POINT;

BIG char2big( ){
    char a[M+3] = {'\0'};
    scanf("%s",a);
    int len = strlen(a);

    BIG res = {{0},1,0};
    if(len == 1 && a[0] == '0') return res;

    res.cnt = len;
    res.flag = 1;
    if(a[0] == '-') {
        res.cnt--;
        res.flag = -1;
        for(int i = len-1; i > 0; i--)
            res.v[len-1-i] = a[i] - '0';
    }

    else for(int i = len-1; i >= 0; i--)
        res.v[len-1-i] = a[i] - '0';

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
    //same cnt
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

BIG st(BIG a){  //copy
    BIG res = {{0},0,0};
    res.flag = a.flag;
    res.cnt = a.cnt;
    for(int i = 0; i < a.cnt; i++) res.v[i] = a.v[i];
    return res;
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

BIG caldis(POINT a, POINT b){//a is ori, b is point
    BIG res = {{0},0,0}, temp = {{0},0,0};
    //dis == 0
    if(cmp(a.x,b.x) == 0 && cmp(a.y,b.y) == 0){
        res.cnt = 1;
        return res;
    }
    //x
    if(cmp(a.x,b.x) == 1) res = minus(a.x,b.x);
    else res = minus(b.x,a.x);
    //y
    if(cmp(a.y,b.y) == 1) temp = minus(a.y,b.y);
    else temp = minus(b.y,a.y);
    //cmp
    if(cmp(res,temp) == -1){
        res.cnt = temp.cnt;
        for(int i = 0; i < res.cnt; i++)
            res.v[i] = temp.v[i];
    }
    res.flag = 1;
    return res;
}

POINT cpy(POINT a){
    POINT res = {{{0},0,0},{{0},0,0},{{0},0,0}};
    //cpy x
    res.x.cnt = a.x.cnt;    res.x.flag = a.x.flag;
    for(int i = 0; i < a.x.cnt; i++){
        res.x.v[i] = a.x.v[i];
    }
    //cpy y
    res.y.cnt = a.y.cnt;    res.y.flag = a.y.flag;
    for(int i = 0; i < a.y.cnt; i++){
        res.y.v[i] = a.y.v[i];
    }
    //cpy dis
    res.dis.cnt = a.dis.cnt;    res.dis.flag = a.dis.flag;
    for(int i = 0; i < a.dis.cnt; i++){
        res.dis.v[i] = a.dis.v[i];
    }
    return res;
}

int main(){
    POINT po[2], ori;
    ori.x = char2big(); ori.y = char2big();

    int n,i;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        //store
        po[1].x = char2big();   po[1].y = char2big();
        po[1].dis = caldis(po[1], ori);

        if(i == 0){
            po[0] = cpy(po[1]);
            continue;
        }

        //compare
        //compare distance
        int Cmp = cmp(po[0].dis,po[1].dis);
        if(Cmp == -1)   continue;
        if(Cmp == 1) {
            po[0] = cpy(po[1]);
            continue;
        }
        if(Cmp == 0) {
            //compare x
            Cmp = cmp(po[0].x,po[1].x);
            if(Cmp == -1)   continue;
            if(Cmp == 1){
                po[0] = cpy(po[1]);
                continue;
            }
            //compare y
            Cmp = cmp(po[0].y,po[1].y);
            if(Cmp == -1)   continue;
            if(Cmp == 1){
                po[0] = cpy(po[1]);
                continue;
            }
        }
    }

    //output
    //distance
    for(int i = po[0].dis.cnt-1; i >= 0; i--)
        printf("%d",po[0].dis.v[i]);
    printf("\n");
    //x
    if(po[0].x.flag == -1) printf("-");
    for(int i = po[0].x.cnt-1; i >= 0; i--)
        printf("%d",po[0].x.v[i]);
    //y
    printf(" ");
    if(po[0].y.flag == -1) printf("-");
    for(int i = po[0].y.cnt-1; i >= 0; i--)
        printf("%d",po[0].y.v[i]);


    return 0;
}
