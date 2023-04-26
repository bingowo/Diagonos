#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int cnt;
    long long num;
}Number;

int cmp(const void *p1, const void *p2){
    Number n1 = *(Number*)p1, n2 = *(Number*)p2;
    if (n1.cnt == n2.cnt)
        return (n1.num > n2.num ? 1: -1);
    return n2.cnt - n1.cnt;
}

void calCnt(Number *Num){
    long long temp = Num->num;
    for (int i = 0; i != 64; ++i){
        Num->cnt += temp & 1;
        temp >>= 1;
    }
}

int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; ++i){
        printf("case #%d:\n", i);
        int N; scanf("%d", &N);
        Number nums[10000];
        for (int j = 0; j != N; ++j){
            scanf("%lld", &nums[j].num);
            nums[j].cnt = 0;
            calCnt(&nums[j]);
        }
        qsort(nums, N, sizeof(Number), cmp);
        for (int j = 0; j != N; ++j)
            printf("%lld%c", nums[j].num, (j == N - 1? '\n': ' '));
    }
    return 0;
}