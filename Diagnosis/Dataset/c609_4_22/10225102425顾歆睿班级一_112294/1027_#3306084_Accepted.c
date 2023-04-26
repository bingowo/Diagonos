#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 500
#define MAXM 10
#define MAXS 11

typedef struct {
    char id[MAXS];
    int score;
} Student;

int cmp(const void *a, const void *b) {
    Student *p = (Student *) a;
    Student *q = (Student *) b;
    if (p->score != q->score) {
        return q->score - p->score;
    } else {
        return strcmp(p->id, q->id);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N, M, G;
        scanf("%d%d%d", &N, &M, &G);
        int score[MAXM];
        for (int j = 0; j < M; j++) {
            scanf("%d", &score[j]);
        }
        Student students[MAXN];
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            int s;
            scanf("%s%d", students[cnt].id, &s);
            students[cnt].score = 0;
            for (int k = 0; k < s; k++) {
                int x;
                scanf("%d", &x);
                students[cnt].score += score[x - 1];
            }
            if (students[cnt].score >= G) {
                cnt++;
            }
        }
        qsort(students, cnt, sizeof(Student), cmp);
        printf("case #%d:\n%d\n", i, cnt);
        for (int j = 0; j < cnt; j++) {
            printf("%s %d\n", students[j].id, students[j].score);
        }
    }
    return 0;
}
