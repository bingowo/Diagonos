#include <stdio.h>

int main() {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    x = x > 0 ? x : -x;
    y = y > 0 ? y : -y;
    long long distance = x + y;
    long long steps = 0;
    if (x % 2 != y % 2) {
        if (distance > (1ULL << 63))
            steps += 64;
        for (int j = 0; j < 64; j++) {
            if ((distance < (1ULL << (j + 1))) && (distance >= (1ULL << j))) {
                steps += (j + distance % 2);
                break;
            }
        }
        printf("%lld\n", steps);
        return 0;
    } else {
        if (x == 0 && y == 0) {
            printf("0\n");
            return 0;
        } else
            printf("-1\n");
        return 0;
    }
}
