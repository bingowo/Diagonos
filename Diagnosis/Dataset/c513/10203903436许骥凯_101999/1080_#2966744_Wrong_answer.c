#include<stdio.h>
#include<string.h>

#define N 100

typedef struct{
    int cnt, v[N];
}BIGINT;

BIGINT input(){
    char s[N+1]; scanf("%s", s);
    int len = strlen(s);
    BIGINT t = {len, {0}};
    for (int i = 0; i != len; i++)
        t.v[i] = s[len - i - 1] - '0';
    return t;
}

void div(BIGINT *t){
    int carry = 0;
    if (t->v[t->cnt - 1] < 2){
        t->cnt--;
        carry = 1;
    }
    for (int i = t->cnt - 1; i >= 0; i--){
        int temp = carry * 10 + t->v[i];
        t->v[i] = temp / 2;
        carry = temp % 2; 
    }
}   

void BtoI(int item, BIGINT *T){
    int carry = item;
    for (int i = 0; i < T->cnt; i++){
        int temp = T->v[i] * 2 + carry;
        T->v[i] = temp % 10;
        carry = temp / 10;
    }
    while(carry){
        T->v[T->cnt++] = carry % 10;
        carry /= 10;
    } 
}

void output(BIGINT T){
    if (T.cnt == 0) T.cnt++;
    for (int i = T.cnt - 1; i > 0; i--)
        printf("%d", T.v[i]);
    printf("%d\n", T.v[0]);
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        printf("case #%d:\n", i);
        BIGINT t = input();
        int bin[334] = {0}, cnt = 0;
        while(t.cnt){
            bin[cnt++] = t.v[0] % 2;
            div(&t);
        }

        for (int j = 0; j < cnt; j++)
            BtoI(bin[j], &t);
        output(t);
    }
    return 0;
}