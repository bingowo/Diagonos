#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num[50];
    int count;
} DATA;

int cmp (const void *a1, const void *b1)
{
    DATA a = *(DATA*)a1;
    DATA b = *(DATA*)b1;
    int i = 0;
    while (i < a.count && i < b.count){
        if (a.num[i] != b.num[i]){
            return b.num[i] - a.num[i];
        }
        i ++;
    }
    if (i < a.count) return -1;
    else return 1;
}

int main()
{
    int T, N;
    scanf("%d", &T);
    for (int t = 0; t < T; t ++){
        scanf("%d", &N);
        DATA *a = (DATA*)malloc(sizeof(DATA) * N);
        for (int i = 0; i < N; i ++){
            int k = 0;
            scanf("%d", &a[i].num[k]);
            while (a[i].num[k] != -1){
                scanf("%d", &a[i].num[++k]);
            }
            a[i].count = k;
        }
        qsort(a, N, sizeof(DATA), cmp);
        for (int i = 0; i < N; i ++){
            for (int j = 0; j < a[i].count; j ++){
                printf("%d ", a[i].num[j]);
            }
            printf("\n");
        }
        free(a);
    }
    return 0;
}