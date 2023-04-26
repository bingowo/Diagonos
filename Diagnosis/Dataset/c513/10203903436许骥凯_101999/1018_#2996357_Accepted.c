#include<stdio.h>
#include<string.h>
#include<math.h>

int table[25];
int isPrime(int a){
    if (a <= 1) return 0;
    if (a == 2) return 1;
    if (!(a % 2)) return 0;
    for (int i = 3; i <= sqrt(a); i += 2)
        if (!(a % i)) return 0;
    return 1;
}
void Init(){
    int tlen = 0;
    for (int i = 2; i != 10000; i++){
        if (isPrime(i)) table[tlen++] = i;
        if (tlen == 25) return;
    }
}

#define N 10000
typedef struct{
    int cnt, v[N];
}BIG;

BIG ItoB(int n){
    BIG res = {0, {0}};
    do{
        res.v[res.cnt++] = n % 10;
        n /= 10;
    }while(n);
    return res;
}

BIG MUL(BIG T, int n){
    BIG res = {0, {0}};
    int carry = 0;
    for (int i = 0; i != T.cnt; i++){
        int temp = T.v[i] * n + carry;
        res.v[res.cnt++] = temp % 10;
        carry = temp / 10;
    }
    while(carry){
        res.v[res.cnt++] = carry % 10;
        carry /= 10;
    }
    return res;
}

BIG ADD(BIG T, BIG S){
    BIG res = {0, {0}};
    int carry = 0;
    for (int i = 0; i != T.cnt; i++){
        int temp = T.v[i] + S.v[i] + carry;
        res.v[res.cnt++] = temp % 10;
        carry = temp / 10;
    }
    for (int i = T.cnt; i < S.cnt; i++){
        int temp = S.v[i] + carry;
        res.v[res.cnt++] = temp % 10;
        carry = temp / 10;
    }
    while(carry){
        res.v[res.cnt++] = carry % 10;
        carry /= 10;
    }
    return res;
}

int main(){
    Init();
    int prime[25]; int plen = 0; char c;
    do{
        scanf("%d", &prime[plen++]);
    }while((c = getchar()) != '\n');
    BIG dec[25];
    for (int i = 0; i < plen; i++){
        BIG temp = ItoB(prime[i]);
        for (int j = 0; j < plen - i - 1; j++)
            temp = MUL(temp, table[j]);
        dec[i] = temp; 
    }
    BIG res = {0, {0}};
    for (int i = plen - 1; i >= 0; i--)
        res = ADD(dec[i], res);
    for (int i = res.cnt - 1; i >= 0; i--) printf("%d", res.v[i]);
    printf("\n");
    return 0;
}