#include<stdio.h>
#include<stdlib.h>

struct number{
    long long int value;
    int cnt_of_1;
};

int one_cnt(long long int a)
{
    long long int b = 1;
    int cnt = 0, i = 0;
    for(i = 0; i < 64; i++){
        if(a & b){
            cnt++;
        }
        b = b << 1;
    }
    return cnt;
}

int cmp(struct number a, struct number b)
{
    if(a.cnt_of_1 == b.cnt_of_1){
        return (a.value > b.value);
    }
    return (a.cnt_of_1 < b.cnt_of_1);
}

int main()
{
    int T,i,j;
    long long int tem;
    scanf("%d",&T);
    getchar();
    struct number obj[10001];
    for(i = 0; i < T; i++){
        int N = 0;
        scanf("%d", &N);
        getchar();
        for(j = 0; j < N; j++){
            scanf("%lld", &tem);
            obj[j].value = tem;
            obj[j].cnt_of_1 = one_cnt(tem);
        }
        getchar();
        qsort(obj, N, sizeof(obj[0]), cmp);
        printf("case #%d:\n", i);
        for(j = 0; j < N; j++){
            printf("%lld ", obj[j].value);
        }
        printf("\n");
    }
    return 0;
}
