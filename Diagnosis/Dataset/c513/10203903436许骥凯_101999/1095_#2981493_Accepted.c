#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10000
typedef struct{
    int cnt, v[N], pos;
}BIG;

BIG process(BIG T, BIG S, int tint){
    if (T.cnt == 0) T.pos = 1;
    if (S.cnt == 0) S.pos = 1;
    if (T.cnt < S.cnt){
        BIG temp = T; T = S; S = temp; 
    }
    else if (T.cnt == S.cnt){
        for (int i = T.cnt - 1; i >= 0; i--){
            if (T.v[i] > S.v[i]) break;
            else if (T.v[i] < S.v[i]){
                BIG temp = T; T = S; S = temp;
                break; 
            }
        }
    }
    BIG res = {T.cnt + 1, {0}, 1};
    if (T.pos == 1 && S.pos == 1 || T.pos == -1 && S.pos == -1){
        int carry = 0;
        for (int i = 0; i != S.cnt; i++){
            int temp = T.v[i] + S.v[i] + carry;
            res.v[i] = temp % 10;
            carry = temp / 10;
        }
        for (int i = S.cnt; i < T.cnt; i++){
            int temp = T.v[i] + carry;
            res.v[i] = temp % 10;
            carry = temp / 10;
        }
        int k = T.cnt;
        while(carry){
            int t = res.v[k] + carry;
            res.v[k++] = t % 10;
            carry = t / 10;
        }
        res.cnt = k > res.cnt? k: res.cnt;
        while(res.cnt > 0 && res.v[res.cnt - 1] == 0) res.cnt--;
        res.pos = T.pos; if (res.cnt == 0) res.pos = 1;

        if (tint){
            if (res.pos == 1){
                int carry = tint;
                k = 0; 
                while(carry){
                    int temp = carry + res.v[k];
                    res.v[k++] = temp % 10;
                    carry = temp / 10;
                }
                res.cnt = k > res.cnt? k: res.cnt;
                while(res.cnt > 0 && res.v[res.cnt - 1] == 0) res.cnt--;
            }
            else{
                int lend = tint;
                int i = 0;
                while(lend){
                    int temp = res.v[i] - lend;
                    res.v[i++] = (10 + temp) % 10;
                    lend = temp >= 0? 0: 1; 
                }
                while(res.cnt > 0 && res.v[res.cnt - 1] == 0) res.cnt--;
            }
        }
    }

    else{
        res.cnt = T.cnt;
        int lend = 0;
        for (int i = 0; i != S.cnt; i++){
            int temp = T.v[i] - S.v[i] - lend;
            res.v[i] = (temp + 10) % 10;
            lend = temp >= 0? 0: 1;
        }
        for (int i = S.cnt; i < T.cnt; i++){
            int temp = T.v[i] - lend;
            res.v[i] = (temp + 10) % 10;
            lend = temp >= 0? 0: 1;
        }
        int k = T.cnt;
        while(lend){
            int temp = res.v[k] - lend;
            res.v[k++] = (10+temp) %10;
            lend = temp>=0? 0: 1;
        }
        while(res.cnt > 0 && res.v[res.cnt - 1] == 0) res.cnt--;
        res.pos = T.pos; if (res.cnt == 0) res.pos = 1;
        if (tint){
            if (res.pos == 1){
                int carry = tint;
                int k = 0; 
                while(carry){
                    int temp = carry + res.v[k];
                    res.v[k++] = temp % 10;
                    carry = temp / 10;
                }
                res.cnt = k > res.cnt? k: res.cnt;
                while(res.cnt > 0 && res.v[res.cnt - 1] == 0) res.cnt--;      
            }
            else{
                int lend = tint;
                for (int i = 0; i != res.cnt; i++){
                    int temp = res.v[i] - lend;
                    res.v[i] = (10 + temp) % 10;
                    lend = temp >= 0? 0: 1; 
                }
                while(res.cnt > 0 && res.v[res.cnt - 1] == 0) res.cnt--;
            }
        }
    }

    while(res.cnt > 0 && res.v[res.cnt - 1] == 0) res.cnt--;
    if (res.cnt == 0) res.pos = 1;
    return res;
}

int main(){
    char s[N], t[N];
    scanf("%s", s);
    int k = 0;
    for (int i = 2; i < strlen(s); i++){
        int d;
        if (s[i] >= 'A') d = s[i] - 'A' + 10;
        else d = s[i] - '0';
        unsigned int flag = 0x8;
        while (flag){
            if (d&flag) t[k++] = '1';
            else t[k++] = '0';
            flag = flag >> 1;
        }
    }
    BIG qr = {0, {0}, 1}, qi = {0, {0}, 1}, a = {0,{0}, 1}, b = {0, {0}, 1};
    for (int i = 0; i < k; i++){
        int r = t[i] - '0';
        qr.pos = -qr.pos, qi.pos = -qi.pos;
        a = process(qr, qi, r);
        qr.pos = -qr.pos;
        b = process(qr, qi, 0);
        qr = a;
        qi = b;    
    }
    if (qi.cnt == 0){
        if (qr.cnt == 0){
            printf("0\n"); return 0;
        }
        if (qr.pos == -1 && qr.cnt != 0) printf("-");
        for (int i = qr.cnt - 1; i >= 0; i--)
            printf("%d", qr.v[i]);
        printf("\n");
    }
    else{
        if (qr.cnt != 0){
            if (qr.pos == -1) printf("-");
            for (int i = qr.cnt - 1; i >= 0; i--)
                printf("%d", qr.v[i]);
            if (qi.pos == 1) printf("+");
        }
        if (qi.cnt == 1 && qi.v[0] == 1 && qi.pos == 1) printf("i\n");
        else if (qi.cnt == 1 && qi.v[0] == 1 && qi.pos == -1) printf("-i\n");
        else{
            if (qi.pos == -1) printf("-");
            for (int i = qi.cnt - 1; i >= 0; i--)
                printf("%d", qi.v[i]);
            printf("i\n"); 
        } 
    }
    return 0;
}