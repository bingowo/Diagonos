#include<stdio.h>

#define N 95

typedef struct{
    int cnt, v[N];
}BIGINT;

BIGINT int2BIG(int a){
    BIGINT R = {0, {0}};
    do{
        R.v[R.cnt++] = a % 10;
        a /= 10;
    }while(a);
    return R;
}

BIGINT mul(BIGINT S, BIGINT T){
    BIGINT R = {S.cnt + T.cnt, {0}};
    for (int i = 0; i != T.cnt; i++){
        int carry = 0;
        for (int j = 0; j != S.cnt; j++){
            int t = S.v[j] * T.v[i] + carry + R.v[i + j];
            R.v[i+j] = t % 10;
            carry = t / 10;
        }
        int k = i + S.cnt;
        while(carry){
            int t = R.v[k] + carry;
            R.v[k++] = t % 10;
            carry = t / 10;
        }
    }
    if (R.v[R.cnt - 1] == 0) R.cnt--;
    return R;
}

BIGINT POW(BIGINT a, int n){
    if (n == 0) return int2BIG(1);
    if (n == 1) return a;
    BIGINT r = POW(a, n / 2);
    r = mul(r, r);
    if (n % 2) r = mul(r, a);
    return r;
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        printf("case #%d:\n", i);
        int a, r; scanf("%d%d", &a, &r);
        BIGINT t = int2BIG(a);
        BIGINT res = POW(t, r);
        for (int j = res.cnt - 1; j >= 1; j--) printf("%d", res.v[j]);
        printf("%d\n", res.v[0]);
    }
    return 0;
}