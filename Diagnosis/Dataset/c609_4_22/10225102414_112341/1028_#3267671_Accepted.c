#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    long long a[51];
}input;

int cmp (const void *a, const void *b)
{
    input *A = (input *)a, *B = (input *)b;
    int i = 0;
    while (A->a[i] == B->a[i]){
        i += 1;
    }
    if (A->a[i] > B->a[i]){
        return -1;
    }else{
        return 1;
    }
}

int main()
{
    int T, N, i, j, k;
    input *n;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        scanf("%d", &N);
        n = (input *)malloc(sizeof(input) * N);
        for (j = 0;j < N;j++){
            k = -1;
            do{
                k += 1;
                scanf("%lld", &n[j].a[k]);
            }while(n[j].a[k] != -1);
        }
        qsort(n, N, sizeof(input), cmp);
        for (j = 0;j < N;j++){
            for (k = 0;n[j].a[k] != -1;k++){
                printf("%lld", n[j].a[k]);
                if (n[j].a[k + 1] == -1){
                    printf("\n");
                }else{
                    printf(" ");
                }
            }
        }
        free(n);
    }
    return 0;
}