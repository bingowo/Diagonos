#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 55

//2,3,5,7,11,
//13,17,19,23,29,   31,37,41,43,47,
//53,59,61,67,71,   73,79,83,89,97,101

typedef struct{
    int v[M];
    int cnt;
}BIG;

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
    BIG prime[26] = {{{0},0}};
    for(int i = 0; i < 26; i++){
        if(i <= 3) prime[i].cnt = 1;
        else if(i <= 24) prime[i].cnt = 2;
        else prime[i].cnt = 3;

        if(i >= 4) prime[i].v[1] = 1;
        if(i >= 8) prime[i].v[1]++;if(i >= 10) prime[i].v[1]++;
        if(i >= 12) prime[i].v[1]++;if(i >= 15) prime[i].v[1]++;
        if(i >= 17) prime[i].v[1]++;if(i >= 19) prime[i].v[1]++;
        if(i >= 22) prime[i].v[1]++;if(i >= 24) prime[i].v[1]++;
    }

    prime[0].v[0] = 2;prime[1].v[0] = 3;    //2-7
    prime[2].v[0] = 5;prime[3].v[0] = 7;
    prime[4].v[0] = 1;prime[5].v[0] = 3;    //11-19
    prime[6].v[0] = 7;prime[7].v[0] = 9;
    prime[8].v[0] = 3;prime[9].v[0] = 9;    //23-29
    prime[10].v[0] = 1;prime[11].v[0] = 7;  //31-37
    prime[12].v[0] = 1;prime[13].v[0] = 3;  //41-47
    prime[14].v[0] = 7;
    prime[15].v[0] = 3;prime[16].v[0] = 9;  //53-59
    prime[17].v[0] = 1;prime[18].v[0] = 7;  //61-67
    prime[19].v[0] = 1;prime[20].v[0] = 3;  //71-79
    prime[21].v[0] = 9;
    prime[22].v[0] = 3;prime[23].v[0] = 9;  //83-89
    prime[24].v[0] = 7;                     //97
    prime[25].v[0] = 1;prime[25].v[1] = 0;  //101
    prime[25].v[2] = 1;


    BIG index[26] = {{{0},0}};
    index[0].cnt = 1, index[0].v[0] = 1;
    index[1].cnt = 1, index[1].v[0] = 2;
    index[2].cnt = 1, index[2].v[0] = 6;

    for(int i = 3; i < 26; i++)
        index[i] = mul(index[i-1],prime[i-1]);


    char temp[M] = {'\0'};
    BIG input[25] = {{{0},0}}, res = {{0},0};
    int num;

    scanf("%s",temp);
    num = readnum(temp,strlen(temp),input);

    res = cal(input,num,index);
    output(res);

    return 0;
}
