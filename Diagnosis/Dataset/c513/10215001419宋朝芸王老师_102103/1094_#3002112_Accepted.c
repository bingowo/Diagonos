#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 121

typedef struct{
    int v[M];
    int cnt;
    int flag;
}BIG;

BIG convert(char *a, int len){  //-12 12
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

BIG put(BIG temp){
    BIG ret = {{0},0,0};
    ret.cnt = temp.cnt;
    ret.flag = temp.flag;
    for(int i = 0; i < temp.cnt; i++){
        ret.v[i] = temp.v[i];
    }
    return ret;
}

int max(int a, int b){
    return a > b ? a : b;
}

BIG minus(BIG a, BIG b){    //a-b
    if(b.flag == 0) return a;

    BIG res = {{0},0,0};
    if(b.flag == a.flag){    //a-b (same flag)
        int t,carry = 0;
        res.flag = a.flag;
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
    }

    else{   //a+b (ignore flag)
        int t,carry = 0;
        for(int i = 0; i < max(a.cnt,b.cnt); i++){
            t = a.v[i] + b.v[i] + carry;
            res.v[res.cnt++] = t%10;
            carry = t/10;
        }
        if(carry > 0){
            res.v[res.cnt++] = carry;
        }
    }

    return res;
}

int main()
{
    int t;
    scanf("%d",&t);

    BIG big = {{0},0,0}, small = {{0},0,0}, temp = {{0},0,0};

    for(int i = 0; i < t; i++){
        char input[M];
        scanf("%s",input);
        temp = convert(input,strlen(input));

        if(i == 0){
            big = put(temp);
            small = put(temp);
        }
        else{
            if(cmp(temp,big) == 1) big = put(temp);
            else if(cmp(small,temp) == 1) small = put(temp);
        }
    }

    BIG res = {{0},0,0};

    res = minus(big,small);
    for(int i = res.cnt-1; i >= 0; i--)
        printf("%d",res.v[i]);

    return 0;
}
