#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stu{
    char id[12];
    int score;
}stu;

int cmp(const void* a, const void* b){
    stu* x = (stu*)a;
    stu* y = (stu*)b;
    if (x->score != y->score) return y->score - x->score;
    else return strcmp(x->id, y->id);
}

int main(){
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++){
        int N, M, G, value[11] = {0}, Gsum = 0;
        stu stuarr[505];
        scanf("%d %d %d", &N, &M, &G);
        for (int i = 1; i <= M; i++){
            scanf("%d", &value[i]);
        }
        for (int i = 0; i < N; i++){
            stu s0;
            s0.score = 0;
            int count;
            scanf("%s %d", s0.id, &count);
            for (int j = 0; j < count; j++){
                int temp = 0;
                scanf("%d", &temp);
                s0.score += value[temp];
            }
            if (s0.score >= G) stuarr[Gsum++] = s0;
        }
        qsort(stuarr, Gsum, sizeof(stu), cmp);
        printf("case #%d:\n%d\n", t, Gsum);
        for (int i = 0; i < Gsum; i++){
            printf("%s %d\n", stuarr[i].id, stuarr[i].score);
        }
    }
    return 0;
}