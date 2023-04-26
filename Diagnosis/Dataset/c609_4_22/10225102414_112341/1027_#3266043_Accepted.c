#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char number[12];
    int S, point;
}stu;

int cmp(const void *a, const void *b)
{
    stu *A = (stu *)a, *B = (stu *)b;
    if (A->point == B->point){
        return strcmp(A->number, B->number);
    }else{
        return B->point - A->point;
    }
}

int main()
{
    int T, N, M, G, i, j, k, *m, s, pass, fail;
    stu *n;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        pass = 0;
        fail = 0;
        scanf("%d%d%d", &N, &M, &G);
        m = (int *)malloc(sizeof(int) * M);
        n = (stu *)malloc(sizeof(stu) * N);
        for (j = 0;j < M;j++){
            scanf("%d", &m[j]);
        }
        for (j = 0;j < N - fail;j++){
            n[j].point = 0;
            scanf("%s%d", n[j].number, &n[j].S);
            for (k = 0;k < n[j].S;k++){
                scanf("%d", &s);
                n[j].point += m[s - 1];
            }
            if (n[j].point < G){
                j -= 1;
                fail += 1;
            }else{
                pass += 1;
            }
        }
        qsort(n, pass, sizeof(stu), cmp);
        printf("case #%d:\n%d\n", i, pass);
        for (j = 0;j < pass;j++){
            printf("%s %d\n", n[j].number, n[j].point);
        }
        free(m);
        free(n);
    }
    return 0;
}