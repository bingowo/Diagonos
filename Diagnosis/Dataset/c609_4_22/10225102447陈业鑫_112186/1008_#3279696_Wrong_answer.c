#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t bytes[8]; // 用 8 个字节的数组储存 int 或 double 变量的值
    double n;
    while (scanf("%lf", &n) == 1) {
        if ((int)n == n) { // 如果是 int 类型
            *(int *)bytes = (int)n; // 将数值存入数组
            for (int i = 0; i < 4; i++) {
                printf("%02x ", bytes[i]); // 以 16 进制格式输出每个字节
            }
            printf("\n");
        } else { // 如果是 double 类型
            *(double *)bytes = n; // 将数值存入数组
            for (int i = 0; i < 8; i++) {
                printf("%02x ", bytes[i]);
            }
            printf("\n");
        }
    }
    return 0;
}