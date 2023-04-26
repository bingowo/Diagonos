#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int score;
    char id[12];
} Student;

int cmp(void const *_a, void const *_b) {
    Student const *a = (Student const *)_a;
    Student const *b = (Student const *)_b;
    if (a->score == b->score)
        return strcmp(a->id, b->id);
    return b->score - a->score;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n, m, g;
        scanf("%d%d%d", &n, &m, &g);

        int points[11];
        for (int j = 1; j <= m; ++j)
            scanf("%d", &points[j]);

        Student students[500];
        for (int j = 0; j < n; ++j) {
            int s;
            students[j].score = 0;
            scanf("%s%d", students[j].id, &s);
            for (int k = 0; k < s; ++k) {
                int solve;
                scanf("%d", &solve);
                students[j].score += points[solve];
            }
        }
        qsort(students, n, sizeof(Student), cmp);

        int passed = 0;
        while (students[passed].score >= g)
            ++passed;
        printf("case #%d:\n%i\n", i, passed);

        for (int j = 0; j < passed; ++j)
            printf("%s %d\n", students[j].id, students[j].score);
    }
}