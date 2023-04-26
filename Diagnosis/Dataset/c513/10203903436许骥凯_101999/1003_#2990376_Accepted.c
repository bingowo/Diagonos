#include<stdio.h>
#include<stdlib.h>
#define ll long long

typedef struct{
    ll value;
    int cnt;
}Number;

int cal(ll a){
    int cnt = 0;
    for (int i = 0; i != 64; i++){
        if (a & 1) cnt++;
        a >>= 1;
    }
    return cnt;
}

int cmp(const void *p1, const void *p2){
    Number n1 = *(Number*)p1, n2 = *(Number*)p2;
    if (n1.cnt == n2.cnt) return n1.value > n2.value? 1: -1;
    return n2.cnt - n1.cnt;
}

int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; i++){
        int n; scanf("%d", &n);
        Number *arr =  (Number*)malloc(sizeof(Number) * n);
        for (int i = 0; i != n; i++){
            scanf("%lld", &arr[i].value);
            arr[i].cnt = cal(arr[i].value);
        }
        qsort(arr, n, sizeof(Number), cmp);
        printf("case #%d:\n", i);
        for (int i = 0; i != n; i++) printf("%lld%c", arr[i].value, i == n - 1? '\n': ' ');
        free(arr);
    }

    return 0;
}