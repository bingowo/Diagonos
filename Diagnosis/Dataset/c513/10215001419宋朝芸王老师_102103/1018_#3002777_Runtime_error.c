#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 55

typedef struct{
    int v[M];
    int cnt;
}BIG;

/*void reverse(int *a, int num){
    int * p = a;
    int temp;
    for(int i = 0; i < num / 2; i++){
        temp = p[i];
        p[i] = p[num - i - 1];
        p[num - i - 1] = temp;
    }
}*/

int readnum(char *tempC, int len, BIG res[]){
    char *pc = tempC;
    int temp = 0, cnt = 0;

    while(*pc == '0' && *(pc+1) == ','){
        pc += 2;
    }
    while(*pc) {
        if(*pc == ','){
            if(temp == 0)
                res[cnt++].cnt = 1;

            else{
                while(temp > 0){
                    res[cnt].v[res[cnt].cnt++] = temp%10;
                    temp = temp/10;
                }
                cnt++;
                temp = 0;
            }
        }
        else temp = temp * 10 + *pc - '0';
        pc++;
    }
    //store rest
    if(temp == 0) res[cnt++].cnt = 1;
    else{
        while(temp > 0){
            res[cnt].v[res[cnt].cnt++] = temp%10;
            temp = temp/10;
        }
        cnt++;
    }
    return cnt;
}

int max(int a, int b){
    return a > b ? a : b;
}

BIG mul(BIG a, BIG b){
    BIG res = {{0},0};
    for(int m = 0; m < b.cnt; m++){
        int t,k,n;
        int carry = 0;

        for(n = 0; n < a.cnt; n++){
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

    res.cnt = a.cnt + b.cnt;
    if(res.v[a.cnt+b.cnt-1] == 0) res.cnt--;
    return res;
}

BIG add(BIG a, BIG b){
    BIG res = {{0},0};
    int t, carry = 0;
    for(int i = 0; i < max(a.cnt,b.cnt); i++){
        t = a.v[i] + b.v[i] + carry;
        res.v[res.cnt++] = t%10;
        carry = t/10;
    }
    if(carry > 0) res.v[res.cnt++] = carry;
    return res;
}

BIG cal(BIG in[], int cnt, const BIG index[]){
    BIG res = {{0},0}, temp = {{0},0};
    for(int i = 0; i < cnt; i++){
        temp = mul(in[i],index[cnt-1-i]);
        res = add(temp,res);
    }

    return res;
}

void output(BIG a){
    for(int i = a.cnt - 1; i >= 0; i--)
        printf("%d",a.v[i]);
}

int main()
{
    const int prime[26] = {2,3,5,7,11,
        13,17,19,23,29,31,37,41,43,47,
        53,59,61,67,71,73,79,83,89,97,101};

    long long int q[26];
    q[0] = 1;
    q[1] = 2;
    q[2] = 6;
    BIG index[26] = {{{0},0}};
    index[0].cnt = 1, index[0].v[0] = 1;
    index[1].cnt = 1, index[1].v[0] = 2;
    index[2].cnt = 1, index[2].v[0] = 6;
    long long store;

    for(int i = 3; i < 26; i++){
        q[i] = q[i-1] * prime[i-1];

        store = q[i];
        while(store > 0){
            index[i].v[index[i].cnt++] = store%10;
            store = store/10;
        }
    }


    char temp[M] = {'\0'};
    BIG input[25] = {{{0},0}}, res = {{0},0};
    int num;

    scanf("%s",temp);
    num = readnum(temp,strlen(temp),input);

    res = cal(input,num,index);
    output(res);

    return 0;
}
