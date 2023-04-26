#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    char s[101], a[101][101];
    char w1[] = "the", w2[] = "a", w3[] = "an", w4[] = "of", w5[] = "for", w6[] = "and";
    for (int t = 0; t < T; t++) {
        gets(s);
        int len = strlen(s);
        int j = 0, k = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                a[j][k] = '\0';
                j++;
                k = 0;
            } else {
                if (s[i] >= 'A' && s[i] <= 'Z')
                    a[j][k] = s[i] + 32;
                else a[j][k]=s[i];
                k++;
            }
        }
        a[j][k] = '\0';
        int count = j + 1;
        for (int i = 0; i <= j; i++) {
            if (strcmp(a[i], w1) == 0 || strcmp(a[i], w2) == 0 || strcmp(a[i], w3) == 0 || strcmp(a[i], w4) == 0 ||
                strcmp(a[i], w5) == 0 || strcmp(a[i], w6) == 0 )
                count--;
        }
        printf("case #%d:\n%d\n", t, count);
    }
    return 0;
}

