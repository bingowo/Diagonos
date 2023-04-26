#include <stdio.h>

#define MAXN 3

int deng[MAXN][MAXN];
int cao[MAXN][MAXN];

int main() {
    int pnum;
    scanf("%d", &pnum);
    for (int mm = 0; mm < pnum; mm++) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                scanf("%d", &cao[i][j]);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                int d = 0;
                for (int x = -1; x <= 1; x++)
                    if (x + i >= 0 && x + i < 3)
                        d += cao[i + x][j];
                for (int y = -1; y <= 1; y++)
                    if (y + j >= 0 && y + j < 3)
                        d += cao[i][y + j];
                d -= cao[i][j];
                if (d % 2)
                    deng[i][j] = 0;
                else
                    deng[i][j] = 1;
            }
        printf("case #%d:\n", mm);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                printf("%d ", deng[i][j]);
            printf("\n");
        }
    }
}