#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) != EOF) { // 循环读入多组数据
        int delta = b * b - 4 * a * c; // 计算判别式
        if (delta < 0) { // 无实数解
            printf("No Answer!\n");
        } else { // 有实数解
            int x1 = (-b + sqrt(delta)) / (2 * a); // 求解一元二次方程
            int x2 = (-b - sqrt(delta)) / (2 * a);
            if (x1 > x2) { // 交换 x1 和 x2，使得 x1 <= x2
                int temp = x1;
                x1 = x2;
                x2 = temp;
            }
            int gcd = a; // 计算 a, b, c 的最大公约数
            if (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
                gcd = a;
            }
            if (c != 0) {
                int temp = c;
                c = a % c;
                a = temp;
                gcd = a;
            }
            if (gcd != 1) { // 如果最大公约数不为 1，则无法分解
                printf("No Answer!\n");
            } else { // 分解为两个一元一次多项式的乘积
                int a1 = 1, c1 = x1 * x2, a2 = 1, c2 = -(x1 + x2);
                printf("%d %d %d %d\n", a1, c1, a2, c2);
            }
        }
    }
    return 0;
}
