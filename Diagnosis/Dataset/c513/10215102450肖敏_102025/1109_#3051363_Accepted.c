#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    int a[9];
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 9; i++) {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        printf("case #%d:\n", t);
        for (int i = 0; i <= 8; i++) {
            if (a[i] == 0)
                continue;
            else {
                if (a[i] > 0) {
                    if (ans != 0) {
                        printf("+");
                    }
                    if (i <= 7 && a[i] != 1) {
                        printf("%d", a[i]);
                    } else if (i == 8) {
                        printf("%d", a[i]);
                    }
                    ans=1;
                } else {
                    if (i <= 7 ) {
                        if(a[i] != -1)
                            printf("%d", a[i]);
                        else
                            printf("-");
                    } else if (i == 8) {
                        printf("%d", a[i]);
                    }
                    ans =1;
                }
                if (i <= 7) {
                    printf("x");
                    if (i != 7) {
                        printf("^%d", 8 - i);
                    }
                }
            }
        }
        if (ans == 0)
            printf("0");
        printf("\n");
    }
    return 0;
}
