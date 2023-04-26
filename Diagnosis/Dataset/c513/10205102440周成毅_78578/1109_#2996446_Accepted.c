#include <stdio.h>

int xi[9];

void pri(int *);

int main() {
    int pnum;
    scanf("%d", &pnum);
    for (int i = 0; i < pnum; i++) {
        for (int j = 8; j >= 0; j--)
            scanf("%d", &xi[j]);
        printf("case #%d:\n", i);
        pri(xi);
    }
    return 0;
}

void pri(int *s) {
    int state = 0;
    for (int i = 8; i >= 1; i--) {
        if (s[i] != 0) {
            if (state == 0) {
                if (s[i] == -1)
                    printf("-");
                else if (s[i] != 1)
                    printf("%d", s[i]);
            } else {
                if (s[i] == -1)
                    printf("-");
                else if (s[i] < 0)
                    printf("%d", s[i]);
                else {
                    printf("+");
                    if (s[i] != 1)
                        printf("%d", s[i]);
                }
            }
            printf("x");
            if (i != 1)
                printf("^%d", i);
            state++;
        }
    }
    if (state == 0 || xi[0] < 0)
        printf("%d", xi[0]);
    else if (xi[0] > 0)
        printf("+%d", xi[0]);
    printf("\n");
}