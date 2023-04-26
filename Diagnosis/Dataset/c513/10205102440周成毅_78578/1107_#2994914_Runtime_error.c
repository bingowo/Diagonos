#include <stdio.h>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int deng[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        int cishu;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                scanf("%d", &cishu);
                if (cishu % 2) {
                    deng[j][k]=deng[j][k]?0:1;
                    for (int l = 0; l < 4; l++) {
                        if (j + dx[l] <= 3 && k + dy[l] <= 3)
                            deng[j + dx[l]][k + dy[l]] = deng[j + dx[l]][k + dy[l]] ? 0 : 1;
                    }
                }
            }
        }
        printf("case #%d:\n", i);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++)
                printf("%d ", deng[j][k]);
            printf("\n");
        }
    }
    return 0;
}
