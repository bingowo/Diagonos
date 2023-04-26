#include <stdio.h>

void add(int *a, int *b, int *c) {  // 实现 a+b=c
    int i, t = 0;
    for (i = 0; i < 5000; i++) {
        c[i] = a[i] + b[i] + t;
        t = c[i] / 10;
        c[i] %= 10;
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    if (n == 0) {  // 边界处理
        printf("0\n");
        return 0;
    }

    int a[5000] = {0}, b[5000] = {0}, c[5000] = {0};
    a[0] = b[0] = 1;  // 初始化

    for (i = 3; i <= n; i++) {
        add(a, b, c);  // 计算第i项斐波那契数列的值，结果存储在 c 数组中
        int j;
        for (j = 0; j < 5000; j++) {
            a[j] = b[j];
            b[j] = c[j];
        }
    }

    int start_printing = 0;
    for (i = 4999; i >= 0; i--) {  // 从高位到低位输出斐波那契数列的第n项
        if (c[i] != 0) {
            start_printing = 1;
        }
        if (start_printing) {
            printf("%d", c[i]);
        }
    }
    printf("\n");
    return 0;
}
