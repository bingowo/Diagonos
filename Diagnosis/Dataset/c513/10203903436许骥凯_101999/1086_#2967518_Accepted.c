#include<stdio.h>
#include<string.h>
#define N 500

typedef struct{
    int cnt, mas, v[2 * N + 1];     
}BIG;

BIG input(){
    char s[502]; scanf("%s", s);
    int idx = 0, len = strlen(s);
    BIG f = {0, 0, {0}};
    while(s[idx] && s[idx] !='.') idx++;
    for (int i = idx + 1, k = N + 1; i < len; i++, k++, f.mas++)
        f.v[k] = s[i] - '0';
    for (int i = idx - 1, k = N; i >= 0; i--, k--, f.cnt++)
        f.v[k] = s[i] - '0'; 
    return f;
}

void exch(BIG *f1, BIG *f2){
    BIG temp = *f1;
    *f1 = *f2;
    *f2 = temp;
}
int cmp(BIG *f1, BIG *f2){
    if (f1->cnt > f2->cnt) return 1;
    if (f1->cnt < f2->cnt){
        exch(f1, f2);    
        return -1;
    }
    
    for (int i = N - f1->cnt + 1; i <= N + f1->mas ; i++){
        if (f1->v[i] > f2->v[i]) return 1;
        if (f1->v[i] < f2->v[i]){
            exch(f1, f2);
            return -1;
        }
    }
    return 0;
}

void sub(BIG f1, BIG f2, int pre){
    int flag = 0;
    if (cmp(&f1, &f2) < 0) flag = 1;  
    int lend = 0;
    for (int i = 2 * N; i > N + pre; i--){
        int temp = f1.v[i] - f2.v[i] - lend;
        f1.v[i] = (10 + temp) % 10;
        lend = temp >= 0? 0: 1;
    }
    if (f1.v[N + pre + 1] >= 5) f1.v[N + pre]++;
    
    for (int i = N + pre; i >= 0; i--){
        int temp = f1.v[i] - f2.v[i] - lend;
        f1.v[i] = (10 + temp) % 10;
        lend = temp >= 0? 0: 1;
    }

    if (flag) printf("-");
    int i = 0;
    while(i <= N && f1.v[i] == 0) i++;
    if (i == N + 1) printf("0"); 
    for (; i <= N; i++) printf("%d", f1.v[i]);
    printf(".");
    for (; i <= N + pre; i++) printf("%d", f1.v[i]);
    printf("\n");
}


int main(){
    BIG f1 = input(), f2 = input();
    int pre; scanf("%d", &pre);
    sub(f1, f2, pre);
    return 0;
}