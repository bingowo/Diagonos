#include<stdio.h>
#define N 100

typedef struct{
    int cnt, v[N];
}BIG;

BIG itoB(int i){
    if (i == 0){
        BIG temp = {1, {0}};
        return temp;
    }
    BIG res = {0, {0}};
    do{
        res.v[res.cnt++] = i % 10;
        i /= 10;
    }while(i);
    return res;
}

void add(BIG* res, const BIG* T){
    int carry = 0;
    for (int i = 0; i != res->cnt; i++){
        int temp = res->v[i] + T->v[i] + carry;
        res->v[i] = temp % 10;
        carry = temp / 10;
    }
    for (int i = res->cnt; i < T->cnt; i++){
        int temp = res->v[i] + T->v[i] + carry;
        res->v[i] = temp % 10;
        carry = temp / 10;
    }
    res->cnt = res->cnt > T->cnt? res->cnt: T->cnt;
    if(carry) res->v[res->cnt++] = carry;
}

int main(){
    BIG dp[101]; int cnt = 3;
    dp[0] = itoB(0), dp[1] = itoB(0), dp[2] = itoB(1);
    for (int i = 3; i != 101; i++)
        dp[i] = itoB(0);
    int n, k; scanf("%d%d", &k, &n);
    if (n < cnt){
        for (int i = 0; i != dp[n].cnt; i++)
            printf("%d", dp[n].v[i]);
        printf("\n");
        return 0;
    }
    while(cnt <= n){
        for (int i = 0; i < k; i++){
            while (cnt + i < k) i++;
            add(&dp[cnt], &dp[cnt - k + i]);
        }
        cnt++;
    }
    for (int i = 0; i != dp[n].cnt; i++)
        printf("%d", dp[n].v[i]);
    printf("\n");
    return 0;
}
