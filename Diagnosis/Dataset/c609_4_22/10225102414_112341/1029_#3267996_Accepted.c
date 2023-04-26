#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num, in;
}input;

int cmp(const void *a, const void *b)
{
    input *x = (input *)a, *y = (input *)b;
    if (x->in != -1 && y->in != -1){
        return x->in - y->in;
    }else if (x->in == -1 && y->in == -1){
        return x->num - y->num;
    }else{
        return (x->in == -1 && y->in != -1) ? 1 : -1;
    }
}

int main()
{
    int m, n, *A, i, j;
    input *B;
    scanf("%d", &m);
    A = (int *)malloc(sizeof(int) * m);
    for(i = 0;i < m;i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &n);
    B = (input *)malloc(sizeof(input) * n);
    for (i = 0;i < n;i++){
        scanf("%d", &B[i].num);
        B[i].in = -1;
        for (j = 0;j < m;j++){
            if (A[j] == B[i].num){
                B[i].in = j;
                break;
            }
        }
    }
    qsort(B, n, sizeof(input), cmp);
    for (i = 0;i < n;i++){
        printf("%d ", B[i].num);
    }
    free(A);free(B);
    return 0;
}
