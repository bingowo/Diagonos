#include <stdio.h>

struct RLE {
    char t;
    int a;
};

struct RLE rle[501];

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        for (int y = 0; y < 501; y++)
            rle[y].a = 1;
        char s[501];
        int j, k;
        scanf("%s", s);
        for (j = 0, k = 0; s[j] != '\0'; j++) {
            if (s[j] == s[j + 1]) {
                if (rle[k].a == 255) {
                    k++;
                    rle[k].t = s[j];
                } else {
                    rle[k].a++;
                    rle[k].t = s[j];
                }
            } else {
                if (j == 0) {
                    rle[k].t = s[j];
                    rle[k+1].t = s[j+ 1];
                } else {
                    k++;
                    rle[k].t = s[j + 1];
                }
            }
        }
        printf("case #%d:\n", i);
        for (int x = 0; x < k; x++)
            printf("%d%c", rle[x].a, rle[x].t);
        printf("\n");

    }
    return 0;
}
