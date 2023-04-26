#include <stdio.h>
#include <stdlib.h>

struct AB {
    int index;
    int digit;
};

struct AB C[500];

int cmp(const void *a, const void *b) {
    struct AB *aa = (struct AB *) a, *bb = (struct AB *) b;
    return aa->index > bb->index;
}

int cmp1(const void *a, const void *b) {
    int *aa = (int *) a, *bb = (int *) b;
    return *aa > *bb;
}

int main() {
    int n, m;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    int B[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }
    int D[500];
    int i, j, k, x;
    for (i = 0, k = 0, x = 0; i < m; i++) {
        int flag = 0;
        for (j = 0; j < n; j++) {
            if (A[j] == B[i]) {
                C[k].digit = B[i];
                C[k].index = j;
                k++;
                flag = 1;
            }
        }
        if (!flag) {
            D[x++] = B[i];
        }
    }
    qsort(C, k, sizeof(C[0]), cmp);
    qsort(D, x, sizeof(D[0]), cmp1);

    for (int y = 0; y < k; y++) {
        printf("%d ", C[y].digit);
    }
    for (int z = 0; z < x; z++) {
        printf("%d ", D[z]);
    }
    return 0;
}
