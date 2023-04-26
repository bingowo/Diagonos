#include <stdio.h>

void Solve() {
    int matrix[3][3];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            scanf("%d", &matrix[i][j]);

    int tmp;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tmp = 0;
            // 左
            if (i > 0)
                tmp += matrix[i-1][j];

            // 右
            if (i < 2)
                tmp += matrix[i+1][j];

            // 上
            if (j > 0)
                tmp += matrix[i][j-1];

            if (j < 2)
                tmp += matrix[i][j+1];

            tmp += matrix[i][j];

            // output
            if (tmp & 1)
                printf("0");
            else
                printf("1");

            if (j == 2)
                printf("\n");
            else printf(" ");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        printf("case #%d:\n", i);
        Solve();
    }
    return 0;
}