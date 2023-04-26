#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100000

typedef struct{
    int Rcnt, Icnt, Rv[N], Iv[N];
    int rp, ip;
}BIG;

BIG ItoB(char *s){
    BIG res = {0, 0, {0}, {0}, 1, 1};
    int len = strlen(s);
    if (s[0] == '0' && len == 1) return res;
    if (s[len - 1] != 'i'){
        res.Rcnt = len;
        int i = 0;
        if (s[0] == '-') res.rp = 0, i = 1, res.Rcnt--;
        for (int k = len - 1; k >= i; k--)
            res.Rv[len - 1 - k] = s[k] - '0';
    }
    else{
        if ((strchr(s+1, '+') == NULL) && (strchr(s+1, '-') == NULL)){
            if (len == 1){
                res.Icnt = 1;
                res.Iv[0] = 1;
            }
            else if (len == 2 && s[0] == '-'){
                res.Icnt = 1;
                res.Iv[0] = 1;
                res.ip = 0;
            }
            else{
                res.Icnt = len - 1;
                int i = 0;
                if (s[0] == '-') res.ip = 0, i = 1, res.Rcnt--;
                for (int k = len - 2; k >= i; k--)
                    res.Iv[len - 2 - k] = s[k] - '0';
            }
        } 
        else{
            int i = 0;
            if(s[0] == '-') res.rp = 0, i++;
            int pidx;
            if (strchr(s + 1, '-') != NULL) pidx = strchr(s + 1, '-') - s;
            else pidx = strchr(s + 1, '+') - s;
            for (int k = pidx - 1; k >= i; k--)
                res.Rv[res.Rcnt++] = s[k] - '0';
            
            if (s[pidx] == '-') res.ip = 0;
            if (s[pidx+1] == 'i') res.Iv[res.Icnt++] = 1;
            else{
                for (int k = len - 2; k > pidx; k--)
                    res.Iv[res.Icnt++] = s[k] - '0';
            }
        }
    }
    return res;
}

BIG mul(BIG T, BIG S){
    BIG temp1 = {T.Rcnt + S.Rcnt, 0, {0}, {0}, !(T.rp ^ S.rp), 1};
    for (int i = 0; i < T.Rcnt; i++){
        int carry = 0;
        for (int j = 0; j < S.Rcnt; j++){
            int t = S.Rv[j] * T.Rv[i] + carry + temp1.Rv[i+j];
            temp1.Rv[i+j] = t % 10;
            carry = t / 10;
        }
        int k = S.Rcnt + i;
        while(carry){
            int t = temp1.Rv[k] + carry;
            temp1.Rv[k++] = t % 10;
            carry = t / 10;
        }
    }
    if(temp1.Rv[temp1.Rcnt - 1] == 0) temp1.Rcnt--;

    BIG temp2 = {T.Icnt + S.Icnt, 0, {0}, {0}, T.ip ^ S.ip, 1};
    for (int i = 0; i < T.Icnt; i++){
        int carry = 0;
        for (int j = 0; j < S.Icnt; j++){
            int t = S.Iv[j] * T.Iv[i] + carry + temp2.Rv[i+j];
            temp2.Rv[i+j] = t % 10;
            carry = t / 10;
        }
        int k = i + S.Icnt;
        while(carry){
            int t = temp2.Rv[k] + carry;
            temp2.Rv[k++] = t % 10;
            carry = t / 10;
        }
    } 
    if(temp2.Rv[temp2.Rcnt - 1] == 0) temp2.Rcnt--;

    BIG temp3 = {0, T.Rcnt + S.Icnt, {0}, {0}, 1, !(T.rp ^ S.ip)};
    for (int i = 0; i < T.Rcnt; i++){
        int carry = 0;
        for (int j = 0; j < S.Icnt; j++){
            int t = T.Rv[i] * S.Iv[j] + carry + temp3.Iv[i+j];
            temp3.Iv[i+j] = t % 10;
            carry = t / 10;
        }
        int k = S.Icnt + i;
        while(carry){
            int t = temp3.Iv[k] + carry;
            temp3.Iv[k++] = t % 10;
            carry = t / 10;
        }
    }
    if(temp3.Iv[temp3.Icnt - 1] == 0) temp3.Icnt--;

    BIG temp4 = {0, T.Icnt + S.Rcnt, {0}, {0}, 1, !(T.ip ^ S.rp)};
    for (int i = 0; i < T.Icnt; i++){
        int carry = 0;
        for (int j = 0; j < S.Rcnt; j++){
            int t = T.Iv[i] * S.Rv[j] + carry + temp4.Iv[i+j];
            temp4.Iv[i+j] = t % 10;
            carry = t / 10;
        }
        int k = i + S.Rcnt;
        while(carry){
            int t = temp4.Iv[k] + carry;
            temp4.Iv[k++] = t % 10;
            carry = t / 10;
        }
    }
    if(temp4.Iv[temp4.Icnt - 1] == 0) temp4.Icnt--;

    if (temp1.Rcnt < temp2.Rcnt){
        BIG temp = temp1;
        temp1 = temp2;
        temp2 = temp;
    }
    else if (temp1.Rcnt == temp2.Rcnt){
        for (int i = temp1.Rcnt - 1; i >= 0; i--){
            if (temp1.Rv[i] < temp2.Rv[i]){
                BIG temp = temp1;
                temp1 = temp2;
                temp2 = temp;
                break;
            }
            else if (temp1.Rv[i] > temp2.Rv[i]) break;
        }
    }
    if (temp3.Icnt < temp4.Icnt){
        BIG temp = temp3;
        temp3 = temp4;
        temp4 = temp;
    }
    else if (temp3.Icnt == temp4.Icnt){
        for (int i = temp3.Icnt - 1; i >= 0; i--){
            if (temp3.Iv[i] < temp4.Iv[i]){
                BIG temp = temp3;
                temp3 = temp4;
                temp4 = temp;
                break;
            }
            else if (temp3.Iv[i] > temp4.Iv[i]) break;
        }
    }

    BIG res = {0, 0, {0}, {0}, 1, 1};
    res.Rcnt = temp1.Rcnt + 1;
    if (!(temp1.rp ^ temp2.rp)){
        if (!temp1.rp) res.rp = 0;
        int carry = 0;
        for (int i = 0; i < temp2.Rcnt; i++){
            int t = temp1.Rv[i] + temp2.Rv[i] + carry;
            res.Rv[i] = t % 10;
            carry = t / 10;
        }
        for (int i = temp2.Rcnt; i < temp1.Rcnt; i++){
            int t = temp1.Rv[i] + carry;
            res.Rv[i] = t % 10;
            carry = t / 10;
        }
        if(carry) res.Rv[temp1.Rcnt] = carry;
    }
    else{
        if (!temp1.rp) res.rp = 0;
        int lend = 0;
        for (int i = 0; i < temp2.Rcnt; i++){
            int t = temp1.Rv[i] - temp2.Rv[i] - lend;
            res.Rv[i] = (10 + t) % 10;
            lend = t > 0? 0: 1;
        }
        for (int i = temp2.Rcnt; i < temp1.Rcnt; i++){
            int t = temp1.Rv[i] - lend;
            res.Rv[i] = (10 + t) % 10;
            lend = t > 0? 0: 1;
        }
    }

    res.Icnt = temp3.Icnt;
    if (!(temp3.ip ^ temp4.ip)){
        if (!temp3.ip) res.ip = 0;
        int carry = 0;
        for (int i = 0; i < temp4.Icnt; i++){
            int t = temp3.Iv[i] + temp4.Iv[i] + carry;
            res.Iv[i] = t % 10;
            carry = t / 10;
        }
        for (int i = temp4.Icnt; i < temp3.Icnt; i++){
            int t = temp3.Iv[i] + carry;
            res.Iv[i] = t % 10;
            carry = t / 10;
        }
        if(carry) res.Iv[temp3.Icnt] = carry;
    }
    else{
        if (!temp3.ip) res.ip = 0;
        int lend = 0;
        for (int i = 0; i < temp4.Icnt; i++){
            int t = temp3.Iv[i] - temp4.Iv[i] - lend;
            res.Iv[i] = (10 + t) % 10;
            lend = t > 0? 0: 1;
        }
        for (int i = temp4.Icnt; i < temp3.Icnt; i++){
            int t = temp3.Iv[i] - lend;
            res.Iv[i] = (10 + t) % 10;
            lend = t > 0? 0: 1;
        }
    }
    while (res.Rcnt > 0 && res.Rv[res.Rcnt - 1] == 0) res.Rcnt--;
    while (res.Icnt > 0 && res.Iv[res.Icnt - 1] == 0) res.Icnt--;
    return res;
}

BIG POW(BIG T, int exp){
    if (exp == 0) return ItoB("1");
    if (exp == 1) return T;
    BIG res = POW(T, exp / 2);
    res = mul(res, res);
    if (exp % 2) res = mul(res, T);
    return res;
}

int main(){
    char s[200]; scanf("%s", s);
    int exp; scanf("%d", &exp);
    BIG t = ItoB(s);
    BIG res = POW(t, exp);
    if (!res.rp) printf("-"); 
    for (int i = res.Rcnt - 1; i >= 0; i--)
        printf("%d", res.Rv[i]);
    if (res.Rcnt != 0 && res.Icnt != 0) printf("%c", res.ip? '+': '-');
    if (res.Icnt == 1 && res.Iv[0] == 1) printf("i"); 
    else{
        for (int i = res.Icnt - 1; i >= 0; i--)
            printf("%d", res.Iv[i]);
        if (res.Icnt != 0) printf("i");
    }
    if (res.Rcnt == 0 && res.Icnt == 0) printf("0");
    printf("\n");
    return 0;
}