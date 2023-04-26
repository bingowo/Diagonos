#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

int a[MAX_N], b[MAX_N], c[MAX_N];

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        int n;
        scanf("%d", &n);
        char s[MAX_N];
        scanf("%s", s);
        int len = strlen(s);
        for (int j = 0; j < len; j++) {
            a[len - j - 1] = s[j] - '0';
        }
        scanf("%s", s);
        len = strlen(s);
        for (int j = 0; j < len; j++) {
            b[len - j - 1] = s[j] - '0';
        }
        int k = 0;
        while (k < n) {
            int r = 0;
            for (int j = 0; j < MAX_N; j++) {
                c[j] += a[j] * b[j] + r;
                r = c[j] / 10;
                c[j] %= 10;
            }
            k++;
        }
        int flag = MAX_N - 1;
        while (flag > 0 && c[flag] == 0) {
            flag--;
        }
        printf("case #%d:", i);
        for (int j = flag; j >= 0; j--) {
            printf("%d", c[j]);
        }
        printf("\n");
    }
    return 0;
}