#include <stdio.h>

int main() {
    int m[201][201];
    int n[201][201];
    int w, h, d;
    char c;
    scanf("%d%d%d%c", &w, &h, &d, &c);
    getchar();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    int r = (d / 90) % 4;
    if (r == 0) {
        printf("%d %d\n", w, h);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                printf("%d", m[i][j]);
                if (j == w - 1)
                    printf("\n");
                else printf(" ");
            }
        }
    } else {
        if (c == 'L')
            r = 4 - r;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (r == 1)
                    n[j][h - 1 - i] = m[i][j];
                else if (r == 2)
                    n[h - 1 - i][w - 1 - j] = m[i][j];
                else
                    n[w - 1 - j][i] = m[i][j];
            }
        }
        if (r % 2 == 1) {
            int temp;
            temp = w;
            w = h;
            h = temp;
        }
        printf("%d %d\n", w, h);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                printf("%d", n[i][j]);
                if (j == w - 1)
                    printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
