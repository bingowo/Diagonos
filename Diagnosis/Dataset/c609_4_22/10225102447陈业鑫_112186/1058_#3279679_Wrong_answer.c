#include <stdio.h>
#include <string.h>

#define MAX_N 1005
#define MAX_L 5000

// 注意：本程序假设除数都是正整数

// 将一个字符串表示的正整数对 2 取余，更新地址为 num 指向的字符串
int mod2(char* num, int len) {
    // 模拟手算过程，按照除数进行非负式除法，计算商和余数
    // 从左往右数，设当前余数为 cur_mod，第 i 位为 digit，则
    // cur_mod = cur_mod * 10 + digit;
    // cur_mod = cur_mod % 2;
    // 商为 cur_quot = cur_mod / 2;
    int cur_quot = 0;
    for (int i = 0; i < len; ++i) {
        int cur_mod = cur_quot * 10 + num[i] - '0';
        num[i] = cur_mod / 2 + '0';
        cur_quot = cur_mod % 2;
    }
    // 如果最高位是 0，将其删除，返回新的字符串长度
    int new_len = len;
    while (new_len > 1 && num[new_len - 1] == '0') {
        --new_len;
    }
    return new_len;
}

// 将一个字符串表示的正整数转换为其负二进制表示
void to_negative_binary(char* num) {
    int len = strlen(num), new_len = len;
    // 将 num 数组中的每一个字符转换为对应的数字
    for (int i = 0; i < len; ++i) {
        num[i] -= '0';
    }
    // 保存每一个操作数的负数，为了方便计算已经将数值全部转换为负数
    char ones_complement[MAX_L], twos_complement[MAX_L]; // 求出相应数的一补数和二补数
    for (int i = 0; i < len; ++i) {
        // 按位取反
        ones_complement[i] = 1 - num[i];
    }
    // 求出补码
    twos_complement[0] = ones_complement[0] + 1;
    for (int i = 1; i < len; ++i) {
        twos_complement[i] = ones_complement[i] + twos_complement[i - 1] / 2;
        twos_complement[i - 1] %= 2;
    }
    // 如果最高位是 1，可能需要补一位
    while (twos_complement[new_len - 1] == 0) {
        --new_len;
    }
    if (twos_complement[new_len - 1] == 1) {
        twos_complement[new_len++] = 1;
    }
    // 将负二进制数转化为字符串
    for (int i = 0; i < new_len; ++i) {
        twos_complement[i] += '0';
    }
    // 取反
    for (int i = 0; i < new_len; ++i) {
        num[i] = 1 - (twos_complement[i] - '0');
    }
    // 处理进位
    int i = 0;
    while (num[i] == 0 && i < new_len) {
        num[i] = 1;
        ++i;
    }
    // 输出负二进制数，从高位到低位
    for (int j = new_len - 1; j >= 0; --j) {
        printf("%d", (int)num[j]);
    }
    printf("\n");
}

int main() {
    char num[MAX_L];
    scanf("%s", num);
    int len = strlen(num);
    // 将 num 压缩为不含前导零的字符串
    while (len > 1 && num[len - 1] == '0') {
        --len;
    }
    if (num[0] == '-') {
        // 如果 num 是负数，则先转化为其相反数，再转化为负二进制数
        for (int i = 1; i < len; ++i) {
            num[i] -= '0';
        }
        num[len - 1] = '\0'; // 删除负号
        mod2(num + 1, len - 1); // 取相反数
        to_negative_binary(num + 1); // 转化为负二进制数
    }
    else {
        // 如果 num 是非负数，则直接转化为负二进制数
        to_negative_binary(num);
    }
    return 0;
}