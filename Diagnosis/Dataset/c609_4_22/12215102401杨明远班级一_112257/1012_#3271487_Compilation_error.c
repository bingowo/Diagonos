#include <stdio.h>
#include <string.h>

const int MAXN = 200;

char str[MAXN];
double pow8[50] = {1.0};
int T;

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%s", str);
        printf("case #%d:\n", i - 1);
        double res = 0.0;
        int len = strlen(s) - 2;
        for (int j = 2; j < strlen(str); j++) {
            res += (str[j] - '0') * pow8[len--];
        }
        printf("%.16f\n", res);
    }
    return 0;
}
