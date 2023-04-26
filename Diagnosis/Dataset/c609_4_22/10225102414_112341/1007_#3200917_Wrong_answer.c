#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    long long num;
    int bit;
}M;

long long cmp(const void* a, const void * b)
{
    M *A = (M*)a, *B = (M*)b;
    if (A->bit == B->bit){
        return A->num - B->num;
    }
    return B->bit - A->bit;
}

int main()
{
    int T, N, i, j, k;
    unsigned long long change;
    M input[10000];
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        scanf("%d", &N);
        for (j = 0;j < N;j++){
            scanf("%lld", &input[j].num);
            change = input[j].num;
            for (k = 0;change != 0;change /= 2){
                k += change % 2;
            }
            input[j].bit = k;
        }
        qsort(input, N, sizeof(M), cmp);
        printf("case #%d:\n", i);
        for (k = 0;k < N;k++){
            printf("%lld ", input[k].num);
            if (k == N - 1){
                printf("\n");
            }
        }
    }
    return 0;
}