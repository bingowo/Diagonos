#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        printf("case #%d:\n", i);
        int x[9];
        for (int j = 8; j >=0; --j) {
            scanf("%d", &x[j]);
        }
        int flag = 0; // 标记是否已输出过非零项
        for (int j = 8; j >= 0; j--) {
            if (x[j] != 0) {
                if (flag) {
                    printf("%c", x[j] > 0 ? '+' : '-');
                } else {
                    flag = 1;
                    if (x[j] < 0) {
                        printf("-");
                    }
                }
                if (x[j] != 1 && x[j] != -1) {
                    printf("%d", x[j] > 0 ? x[j] : -x[j]);
                } else if (j == 0) {
                    printf("%d", x[j] > 0 ? x[j] : -x[j]);
                }
                if (x[j] != 0 && j != 0) {
                    printf("x");
                    if (j != 1) {
                        printf("^%d", j);
                    }
                }
            }
        }
        if (!flag) {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
