#include <stdio.h>

int mm[100][100];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int bit[8];

void solve(int x, int y) {
    for (int i = 0; i < 8; i++) {
        if (mm[x + dx[i]][y + dy[i]] >= mm[x][y])
            bit[i] = 1;
        else
            bit[i] = 0;
    }
    int sum = 256, tmp = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = i; j < i + 8; j++)
            tmp = 2 * tmp + bit[j % 8];
        if (tmp < sum)
            sum = tmp;
        tmp = 0;
    }
    printf("%d ", sum);
}

int main() {
    int w, h;
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; ++j)
            scanf("%d", &mm[i][j]);
    for (int i = 1; i < h - 1; i++) {
        for (int j = 1; j < w - 1; j++)
            solve(i, j);
        printf("\n");
    }

    return 0;
}
