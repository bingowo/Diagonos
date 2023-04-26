#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    long long a[50];
}input;

int cmp (const void *a, const void *b)
{
    input *A = (input *)a, *B = (input *)b;
    int i = 0;
    while (A->a[i] == B->a[i]){
        i += 1;
    }
    return B->a[i] - A->a[i];
}

int main()
{
    int T, N, i, j, k;
    input *n;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        scanf("%d", &N);
        n = (input *)malloc(sizeof(input) * N);
        memset(n, 0, sizeof(input) * N);
        for (j = 0;j < N;j++){
            k = -1;
            do{
                k += 1;
                scanf("%d", &n[j].a[k]);
            }while(n[j].a[k] != -1);
        }
        qsort(n, N, sizeof(input), cmp);
        for (j = 0;j < N;j++){
            for (k = 0;n[j].a[k] != -1;k++){
                printf("%d ", n[j].a[k]);
            }
            printf("\n");
        }
        free(n);
    }
    return 0;
}