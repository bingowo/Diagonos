#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    // 计算到达点(x, y)的曼哈顿距离
    long long dist = abs(x) + abs(y);
    // 计算到达点(x, y)需要的最小步数
    long long step = 0;
    while (dist > 0) {
        step++;
        dist -= pow(2, step - 1);
    }
    printf("%lld\n", step);
    return 0;
}
