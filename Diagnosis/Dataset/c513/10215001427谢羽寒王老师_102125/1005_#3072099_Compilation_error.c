#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; ++i) {
        char s[100];
        gets(s);
        int k = 0;
        int sd[155];
        memset(sd, 0, sizeof sd);
        for (int i = strlen(s) - 1; i >= 2; --i) {
            int n = (s[i] - '0'), j;
            for (j = 0; j < k || n; ++j) {
                int tmp = 10 * n + (j < k ? sd[j]: 0);
                sd[j] = tmp / 8;
                n = tmp % 8;
            }
            k = j;
        }
        printf("case #%d:\n0.", i);
        for(int i = 0; i < k; ++i) {
            printf("%d", sd[i]);
        }
        printf("\n");
    }
    return 0;