#include <stdio.h>

int main() {
    int m[201][201];
    int n[201][201];
    int w, h, d;
    char c;
    scanf("%d%d%d", &w, &h, &d);
    
    scanf("%c",&c);
    getchar();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    int r = (d / 90) % 4;
    if (c == 'L' && r != 0)
        r = 4 - r;
    if (r % 2 == 1) {
        int temp;
        temp = w;
        w = h;
        h = temp;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (r == 0)
                n[i][j] = m[i][j];
            else if (r == 1)
                n[i][j] = m[w-1-j][i];
            else if (r == 2)
                n[i][j] = m[h-1-i][w-1-j];
            else
                n[i][j] = m[j][h-1-i];
        }
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
    return 0;
}
