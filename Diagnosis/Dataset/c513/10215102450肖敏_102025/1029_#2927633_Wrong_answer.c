#include <stdio.h>
#include <stdlib.h>


int main() {
    int T, j;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char a[201], temp;
        for (j = 0;a[j] !='\0'; j++) {
            a[j] = getchar();
        }
        for (int k = 0; k < j; k++) {
            if (a[k] >= 'A' && a[k] <= 'Z') {
                for (int y = k+1; y < j; y++) {
                    if (a[y] >= 'A' && a[y] <= 'Z') {
                        if ((int)a[k] >(int)a[y]) {
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
