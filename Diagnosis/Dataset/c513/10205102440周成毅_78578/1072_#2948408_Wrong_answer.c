#include <stdio.h>

long long ABS(long long a) {
    return a > 0 ? a : -a;
}

//void path(long long x, long long y, int square) {
//    if (x == 1 && y == 0) {
//        printf("E");
//        return;
//    } else if (x == -1 && y == 0) {
//        printf("W");
//        return;
//    } else if (x == 0 && y == 1) {
//        printf("N");
//        return;
//    } else if (x == 0 && y == -1) {
//        printf("S");
//        return;
//    } else {
//        if (ABS((1 << square) - ABS(x)) > ABS((1 << square) - ABS(y))) {
//            if (ABS(y - (1 << square)) > ABS(y + (1 << square))) {
//                long long tmp = y - (1 << square);
//                path(x, tmp, square - 1);
//                printf("S");
//            } else {
//                long long tmp = y + (1 << square);
//                path(x, tmp, square - 1);
//                printf("N");
//            }
//        } else {
//            if (ABS(x - (1 << square)) > ABS(x + (1 << square))) {
//                long long tmp = x - (1 << square);
//                path(tmp, y, square - 1);
//                printf("W");
//            } else {
//                long long tmp = x + (1 << square);
//                path(tmp, y, square - 1);
//                printf("E");
//            }
//        }
//    }
//}

int main() {
    long long x, y;
    int steps;
    char path[64];
    int len = 0;
    scanf("%lld %lld", &x, &y);
    if ((ABS(x) + ABS(y))%2 == 0) {
        printf("-1\n");
        return 0;
    } else {
        long long distance = ABS(x) + ABS(y);
        for (int i = 0; i < 64; i++) {
            if (distance < (1LL << (i + 1)) && distance > (1LL << i)) {
                steps = i;
                break;
            }
        }
        while (x != 0 && y != 0) {
            if (ABS((1 << steps) - ABS(x)) > ABS((1 << steps) - ABS(y))) {
                if (ABS(y - (1 << steps)) > ABS(y + (1 << steps))) {
                    y = y + (1 << steps);
                    steps--;
                    path[len++] = 'S';
                    continue;
                } else {
                    y = y - (1 << steps);
                    steps--;
                    path[len++] = 'N';
                    continue;
                }
            } else {
                if (ABS(x - (1 << steps)) > ABS(x + (1 << steps))) {
                    x = x - (1 << steps);
                    steps--;
                    path[len++] = 'W';
                    continue;
                } else {
                    x = x + (1 << steps);
                    steps--;
                    path[len++] = 'E';
                    continue;
                }
            }
        }
        path[len]='\0';
    }
    for(int i=len-1;i>=0;i--)
        printf("%c",path[i]);
    printf("\n");
    return 0;
}