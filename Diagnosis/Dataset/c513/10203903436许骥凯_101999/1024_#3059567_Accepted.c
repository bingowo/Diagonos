#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char id[12];
    int grade;
} student;

int cmp(const void* p1, const void* p2) {
    student stu_a = *(student*)p1, stu_b = *(student*)p2;
    if (stu_a.grade == stu_b.grade)
        return strcmp(stu_a.id, stu_b.id);
    return stu_b.grade - stu_a.grade;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i != T; ++i) {
        student arr_stu[500];
        int scores[10];
        int N, M, G, cnt = 0;
        scanf("%d%d%d", &N, &M, &G);
        for (int j = 0; j != M; ++j)
            scanf("%d", &scores[j]);
        for (int j = 0; j != N; ++j) {
            int S;
            scanf("%s%d", arr_stu[j].id, &S);
            arr_stu[j].grade = 0;
            for (int k = 0; k != S; ++k) {
                int idx;
                scanf("%d", &idx);
                arr_stu[j].grade += scores[idx - 1];
            }
            if (arr_stu[j].grade >= G)
                ++cnt;
        }
        printf("case #%d:\n%d\n", i, cnt);
        qsort(arr_stu, N, sizeof(arr_stu[0]), cmp);
        for (int j = 0; j != cnt; ++j)
            printf("%s %d\n", arr_stu[j].id, arr_stu[j].grade);
    }
    return 0;
}