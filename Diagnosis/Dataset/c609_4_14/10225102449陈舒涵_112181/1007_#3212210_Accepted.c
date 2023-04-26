#include <stdio.h>
#include <stdlib.h>

int count(long long x)
{
    int n = 0;
    if (x >= 0){
        while(x > 0){
            if (x % 2 == 1) n ++;
            x /= 2;
        }
    }
    else{
        x = -x;
        long long a[64] = {0};
        a[0] = 1;
        n ++;
        for (int i = 63; i > 0; i --){
            a[i] = 1 - x % 2;
            x /= 2;
        }
        long long last = 0;
        a[63] += 1;
        for (int i = 63; i > 0; i --){
            a[i] += last;
            if (a[i] == 2){
                a[i] = 0;
                last = 1;
            }
            else{
                last = 0;
            }
            if (a[i] == 1) n ++;
        }
    }
    return n;
}

int cmp(const void *a1, const void *b1)
{
    long long a = *(long long*)a1;
    long long b = *(long long*)b1;
    int na, nb;
    na = count(a);
    nb = count(b);
    if (na != nb){
        return nb - na;
    }
    else{
        if (a > b) return 1;
        else if(a < b) return -1;
        else return 0;
    }
}

int main()
{
    int T, N;
    scanf("%d", &T);
    for (int t = 0; t < T; t ++){
        scanf("%d", &N);
        long long num[N];
        for (int i = 0; i < N; i ++){
            scanf("%lld", &num[i]);
        }
        qsort(num, N, sizeof(long long), cmp);
        printf("case #%d:\n", t);
        for (int i = 0; i < N; i ++){
            printf("%lld ", num[i]);
        }
        printf("\n");
    }
    return 0;
}