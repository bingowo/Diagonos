#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, n, r;
    scanf("%d", &t); // 读入测试数据组数

    while (t--) {
        scanf("%d %d", &n, &r); // 读入待转换的十进制数和目标进制
        int sign = 1;
        if (n < 0) {
            sign = -1; // 记录符号
            n = -n; // 转换为正数
        }
        char ans[100]; // 用于存储转换后的结果
        int idx = 0; // ans数组的下标
        while (n) { // 当n不为0时
            int digit = n % r; // 求n在目标进制下的最低位数字
            if (digit < 10) {
                ans[idx++] = digit + '0'; // 如果是一位数，则直接加上字符'0'
            } else {
                ans[idx++] = digit - 10 + 'A'; // 如果是两位数及以上，则用字符表示，如'A'表示10
            }
            n /= r; // 更新n的值
        }
        if (sign == -1) {
            printf("-"); // 输出负号
        }
        for (int i = idx-1; i >= 0; i--) { // 倒序输出结果
            printf("%c", ans[i]);
        }
        printf("\n"); // 输出换行符
    }

    return 0;
}
