#include <stdio.h>

long long ABS(long long a) {
    return a > 0 ? a : -a;
}

int main() {
    long long x, y;
    int steps, steps1;
    char path[64];
    int len = 0;
    scanf("%lld %lld", &x, &y);
    if (x == 0 && y == 0) {
        printf("0\n");
        return 0;
    }
    if ((ABS(x) + ABS(y)) % 2 == 0) {
        printf("-1\n");
        return 0;
    } else {
        long long distance = ABS(x) + ABS(y);
        for (int i = 0; i < 64; i++) {
            if (distance < (1LL << (i + 1)) && distance > (1LL << i)) {
                steps = i;
                steps1 = i;
                break;
            }
        }
        while (x != 0 || y != 0) {
            if (ABS((1LL << steps) - ABS(x)) > ABS((1LL << steps) - ABS(y))) {
                if (ABS(y - (1LL << steps)) > ABS(y + (1LL << steps))) {
                    y = y + (1LL << steps);
                    steps--;
                    path[len++] = 'S';
                    continue;
                } else {
                    y = y - (1LL << steps);
                    steps--;
                    path[len++] = 'N';
                    continue;
                }
            } else {
                if (ABS(x - (1LL << steps)) > ABS(x + (1LL << steps))) {
                    x = x + (1LL << steps);
                    steps--;
                    path[len++] = 'W';
                    continue;
                } else {
                    x = x - (1LL << steps);
                    steps--;
                    path[len++] = 'E';
                    continue;
                }
            }
        }
        path[len] = '\0';
    }
    printf("%d\n", steps1 + 1);
    for (int i = len - 1; i >= 0; i--)
        printf("%c", path[i]);
    printf("\n");
    return 0;
}