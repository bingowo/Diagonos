#include<stdio.h>
#include<stdlib.h>
#define ll long long

typedef struct{
    ll digit;
    int cnt;
}Number;

int cal(ll n){
    int res = 0;
    for (int i = 0; i != 64; i++){
        if (n & 1) res++;
        n >>= 1;
    }
    return res;
}

int cmp(const void *p1, const void *p2){
    Number n1 = *(Number*)p1, n2 = *(Number*)p2;
    if (n1.cnt == n2.cnt) return n1.digit > n2.digit? 1: -1;
    return n2.cnt - n1.cnt;
}

int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; i++){
        printf("case #%d:\n", i);
        int n; scanf("%d", &n);
        Number* nums = (Number*)malloc(sizeof(Number) * n);
        for (int i = 0; i != n; i++){
            scanf("%lld", &nums[i].digit);
            nums[i].cnt = cal(nums[i].digit);
        }
        qsort(nums, n, sizeof(Number), cmp);
        for (int i = 0; i != n; i++) printf("%lld%c", nums[i].digit, i == n - 1? '\n': ' ');
    }
    return 0;
}