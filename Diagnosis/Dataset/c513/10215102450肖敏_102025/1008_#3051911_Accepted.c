#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int s[20], t[20];
        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));
        int a, b;
        scanf("%d%d", &a, &b);
        int i = 0, j = 0;
        while (a != 0) {
            s[i++] = a % 2;
            a /= 2;
        }
        while (b != 0) {
            t[j++] = b % 2;
            b /= 2;
        }
        int num = 0;
        for (int k = 0; k < 20; k++) {
            if (s[k] != t[k])
                num++;
        }
        printf("%d\n", num);
    }
    return 0;
}
