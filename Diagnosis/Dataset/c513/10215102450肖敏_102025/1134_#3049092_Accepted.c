#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stu {
    char s[11];
    int C, M, E, A;
};

int cmp1(const void *a, const void *b) {
    struct stu *aa = (struct stu *) a, *bb = (struct stu *) b;
    if (aa->C != bb->C)
        return bb->C - aa->C;
    return strcmp(aa->s, bb->s);
}

int cmp2(const void *a, const void *b) {
    struct stu *aa = (struct stu *) a, *bb = (struct stu *) b;
    if (aa->M != bb->M)
        return bb->M - aa->M;
    return strcmp(aa->s, bb->s);
}

int cmp3(const void *a, const void *b) {
    struct stu *aa = (struct stu *) a, *bb = (struct stu *) b;
    if (aa->E != bb->E)
        return bb->E - aa->E;
    return strcmp(aa->s, bb->s);
}

int cmp4(const void *a, const void *b) {
    struct stu *aa = (struct stu *) a, *bb = (struct stu *) b;
    if (aa->A != bb->A)
        return bb->A - aa->A;
    return strcmp(aa->s, bb->s);
}

struct stu ST[100];

int main() {
    int T;
    scanf("%d", &T);
    for (int j = 0; j < T; j++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s%d%d%d", ST[i].s, &ST[i].C, &ST[i].M, &ST[i].E);
            ST[i].A = (ST[i].C + ST[i].M + ST[i].E) / 3.0+0.5;
        }
        printf("case #%d:\n", j);
        qsort(ST, n, sizeof(ST[0]), cmp4);
        printf("A:\n");
        if (n == 1)
            printf("%s\n", ST[0].s);
        for (int k = 0; k < n - 1; k++) {
            if (ST[k].A != ST[k + 1].A) {
                printf("%s\n", ST[k].s);
                break;
            } else {
                printf("%s\n", ST[k].s);
                if (k == n - 2) {
                    printf("%s\n", ST[k + 1].s);
                }
            }
        }
        qsort(ST, n, sizeof(ST[0]), cmp1);
        printf("C:\n");
        if (n == 1)
            printf("%s\n", ST[0].s);
        for (int k = 0; k < n - 1; k++) {
            if (ST[k].C != ST[k + 1].C) {
                printf("%s\n", ST[k].s);
                break;
            } else {
                printf("%s\n", ST[k].s);
                if (k == n - 2) {
                    printf("%s\n", ST[k + 1].s);
                }
            }
        }
        qsort(ST, n, sizeof(ST[0]), cmp2);
        printf("M:\n");
        if (n == 1)
            printf("%s\n", ST[0].s);
        for (int k = 0; k < n - 1; k++) {
            if (ST[k].M != ST[k + 1].M) {
                printf("%s\n", ST[k].s);
                break;
            } else {
                printf("%s\n", ST[k].s);
                if (k == n - 2) {
                    printf("%s\n", ST[k + 1].s);
                }
            }
        }
        qsort(ST, n, sizeof(ST[0]), cmp3);
        printf("E:\n");
        if (n == 1)
            printf("%s\n", ST[0].s);
        for (int k = 0; k < n - 1; k++) {
            if (ST[k].E != ST[k + 1].E) {
                printf("%s\n", ST[k].s);
                break;
            } else {
                printf("%s\n", ST[k].s);
                if (k == n - 2) {
                    printf("%s\n", ST[k + 1].s);
                }
            }
        }
    }
    return 0;
}