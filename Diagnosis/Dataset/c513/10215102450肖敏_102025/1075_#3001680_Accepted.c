#include <stdio.h>

#define SIZE 201
typedef struct {
    int val;
    char dir;
} elem;

void path(elem A[][SIZE], int m, int n) {
    int i, j;
    for (i = 1; i < m; i++) {
        A[i][0].val += A[i - 1][0].val;
        A[i][0].dir = 'D';
    }
    for (i = 1; i < n; i++) {
        A[0][i].val += A[0][i - 1].val;
        A[0][i].dir = 'R';
    }
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            if (A[i][j - 1].val < A[i - 1][j].val) {
                A[i][j].val += A[i][j - 1].val;
                A[i][j].dir = 'R';
            } else {
                A[i][j].val += A[i - 1][j].val;
                A[i][j].dir = 'D';
            }
        }
    }
}

void path2(elem A[][SIZE], int r, int c) {
    if (r == 0 && c == 0)
        return;
    if (A[r][c].dir == 'D') {
        path2(A, r - 1, c);
        putchar('D');
    } else {
        path2(A, r, c - 1);
        putchar('R');
    }
}

int main() {
    elem A[SIZE][SIZE];
    int m, n;
    int i, j;
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j].val);
            A[i][j].dir = 0;
        }
    }
    path(A, m, n);
    printf("%d\n", A[m - 1][n - 1].val);
    path2(A, m - 1, n - 1);
    printf("\n");
    return 0;
}
