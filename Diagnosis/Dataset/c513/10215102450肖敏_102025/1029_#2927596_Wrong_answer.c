#include <stdio.h>
#include <stdlib.h>


int main() {
    int T, j;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char a[201], c, temp;
        for (j = 0; (c = getchar()) != EOF; j++) {
            a[j] = c;
        }
        for (int k = 0; k < j; k++) {
            if (a[k] >= 'A' && a[k] <= 'Z') {
                for (int y = k; y < j; y++) {
                    if (a[y] >= 'A' && a[y] <= 'Z') {
                        if (a[k] > a[y]) {
                            temp = a[k];
                            a[k] = a[y];
                            a[y] = temp;
                        } else continue;
                    } else continue;
                }
            } else continue;
        }
        printf("case #%d:\n", i);
        for (int x = 0; x < j; x++)
            printf("%c", a[x]);
        printf("\n");
    }
    return 0;
}
