#include <stdio.h>
#include <string.h>

const int MAXN = 200;

char s[MAXN];
double pow8[50] = {1.0};
int T;

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%s", s);
        printf("case #%d:\n", i - 1);
        double res = 0.0;
        int len = strlen(s) - 2;
        for (int j = 2; j < strlen(s); j++) {
            res += (s[j] - '0') * pow8[len--];
        }
        printf("%.16f\n", res);
    }
    return 0;
}
