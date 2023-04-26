#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[12];
    int S;
    int question[10];
    int sum;
} STUDENT;

int cmp (const void *a1, const void *b1)
{
    STUDENT a = *(STUDENT*)a1;
    STUDENT b = *(STUDENT*)b1;
    if (a.sum != b.sum){
        if (a.sum < b.sum) return 1;
        else return -1;
    }
    else{
        return strcmp(a.id, b.id);
    }
}

int main()
{
    int T, N, M, G, p, s;
    scanf("%d", &T);
    for (int t = 0; t < T; t ++){
        scanf("%d %d %d", &N, &M, &G);
        int score[M];
        for (int i = 0; i < M; i ++){
            scanf("%d", &score[i]);
        }  //读取每题的分值
        p = 0;
        STUDENT *a = (STUDENT*)malloc(sizeof(STUDENT) * N);
        for (int i = 0; i < N; i ++){  //依次读取每个学生的数据
            scanf("%s %d", a[p].id, &a[p].S);
            s = 0;  //s用于记录当前学生的总分
            for (int j = 0; j < a[p].S; j ++){
                scanf("%d", &a[p].question[j]);
                s += score[a[p].question[j] - 1];
            }
            if (s >= G){
                a[p].sum = s;
                p ++;
            }  //STUDENT仅记录合格学生的数据，p为其下标,最后得到的p为合格学生数量
        }
        qsort(a, p, sizeof(STUDENT), cmp);
        printf("case #%d:\n%d\n", t, p);
        for (int i = 0; i < p; i ++){
            printf("%s %d\n", a[i].id, a[i].sum);
        }
        free(a);
    }
    return 0;
}