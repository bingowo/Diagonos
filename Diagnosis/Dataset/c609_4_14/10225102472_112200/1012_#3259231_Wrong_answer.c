#include <stdio.h>
#include <string.h>
#define MAXN 50 // 八进制数最大位数
#define BASE 8 // 进制
#define PREC 3 // 每一位八进制数对应的十进制位数

int main() {
    int T; // 测试用例个数
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        char octal[MAXN + 1]; // 八进制数字符串
        scanf("%s", octal);
        int len = strlen(octal); // 八进制数长度
        printf("case #%d:\n", t); // 输出用例编号
        printf("0."); // 输出小数点
        int decimal[MAXN * PREC + 1] = {0}; // 高精度十进制数组，初始为0
        int pos = 0; // 当前十进制数组的位置
        for (int i = 2; i < len; i++) { // 遍历八进制数每一位，跳过前两位"0."
            int digit = octal[i] - '0'; // 当前八进制位的数字值
            for (int j = PREC - 1; j >= 0; j--) { // 将当前八进制位转换为PREC位的十进制，并存入数组中
                decimal[pos + j] += digit % BASE;
                digit /= BASE;
            }
            pos += PREC; // 更新位置
        }
        for (int i = MAXN * PREC; i >= 0; i--) { // 处理十进制数组中的进位和借位，使每一位都在[0,9]范围内
            if (decimal[i] >= BASE) {
                decimal[i - 1] += decimal[i] / BASE;
                decimal[i] %= BASE;
            } else if (decimal[i] < 0) {
                decimal[i - 1]--;
                decimal[i] += BASE;
            }
        }
        while (decimal[pos] == 0 && pos > 0) pos--; // 去掉尾部多余的零，但至少保留一位有效数字
        for (int i = 0; i <= pos; i++) { // 输出十进制结果
            printf("%d", decimal[i]);
        }
        printf("\n"); // 换行符号结束输出 
    }
    return 0;
}