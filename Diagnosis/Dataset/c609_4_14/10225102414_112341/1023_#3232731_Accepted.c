#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char d[5], m[10], y[5];
}Maya;

int cmp(const void *a, const void *b)
{
    int da, db, ma ,mb, ya, yb;
    Maya *A = (Maya *)a, *B = (Maya *)b;
    char M[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    for (int i = 0;i < 20;i++){
        if (strcmp(M[i], A->m) == 0){
            ma = i;
        }
        if (strcmp(M[i], B->m) == 0){
            mb = i;
        }
    }
    da = atoi(A->d);ya = atoi(A->y);db = atoi(B->d);yb = atoi(B->y);
    if (strcmp(A->y, B->y) == 0){
        if (strcmp(A->m, B->m) == 0){
            return da - db;
        }else{
            return ma - mb;
        }
    }else{
        return ya - yb;
    }
}

int main()
{
    int T, N, i, j;
    Maya *I;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        scanf("%d", &N);
        I = (Maya *)malloc(sizeof(Maya) * N);
        for (j = 0;j < N;j++){
            scanf("%s%s%s", I[j].d, I[j].m, I[j].y);
        }
        qsort(I, N, sizeof(Maya), cmp);
        printf("case #%d:\n", i);
        for (j = 0;j < N;j++){
            printf("%s %s %s\n", I[j].d, I[j].m, I[j].y);
        }
        free(I);
    }
    return 0;
}