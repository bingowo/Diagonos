#include<stdio.h>
#include<stdlib.h>

struct data{
    long long int a;
    int number;
};

int cmp(const void *p1, const void *p2){
    struct data d1 = *(struct data*)p1, d2 = *(struct data*)p2;
    if (d2.number != d1.number)
        return d2.number - d1.number;
    else{
        if (d1.a > d2.a) return 1;
        else return -1;
    }
}

void solve(){
    struct data p[10000];
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%lld", &p[i].a);
        long long mask = 1;
        p[i].number = 0;
        for (int t = 0; t < 64; t++){
            if (p[i].a & mask) p[i].number++;
            mask = mask << 1;
        }
    }
    qsort(p, N, sizeof(p[0]), cmp);
    for (int i = 0; i < N; i++)
        printf("%lld%c", p[i].a, (i == N - 1? '\n': ' '));
}

int main(){
    int T;
    scanf("%d", &T);
    for (int cas  = 0; cas < T; cas++){
        printf("case #%d:\n", cas);
        solve();
    }
    return 0;
}