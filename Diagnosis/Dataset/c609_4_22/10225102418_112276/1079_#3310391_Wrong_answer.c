#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    while (scanf("%dx^2+%dx+%d", &a, &b, &c) != EOF) { // 循环读入多组数据
        int delta = b * b - 4 * a * c; // 计算判别式
        if (delta < 0) { // 无实数解
            printf("No Answer!\n");
        } else { // 有实数解
            int x1 = (-b + sqrt(delta)) / (2 * a); // 求解一元二次方程
            int x2 = (-b - sqrt(delta)) / (2 * a);
            if (x1 > x2) { // 保证 x1 <= x2
                int temp = x1;
                x1 = x2;
                x2 = temp;
            }
            int a1 = 1, c1 = x1 + x2, a2 = a, c2 = x1 * x2; // 计算分解式
            printf("%d %d %d %d\n", a1, c1, a2, c2);
        }
    }
    return 0;
}
