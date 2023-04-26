#include <stdio.h>
#include <string.h>
//定义一个数组来存储高精度的数，每个元素表示一位数字
#define MAX_LEN 1000
int num[MAX_LEN];

//定义一个函数，用高精度算法计算a的n次方，结果存储在num数组中
void power(int a, int n) {
    //初始化num为1
    memset(num, 0, sizeof(num));
    num[0] = 1;
    //循环n次，每次乘以a
    for (int i = 0; i < n; i++) {
        //定义一个进位变量
        int carry = 0;
        //从低位到高位遍历num数组，每个元素乘以a并加上进位
        for (int j = 0; j < MAX_LEN; j++) {
            int temp = num[j] * a + carry;
            num[j] = temp % 10; //取余数作为当前位的值
            carry = temp / 10; //取商作为进位的值
        }
    }
}

//定义一个函数，打印num数组中的数
void print_num() {
    //找到最高位的下标
    int high = MAX_LEN - 1;
    while (high > 0 && num[high] == 0) {
        high--;
    }
    //从高位到低位打印每个元素
    for (int i = high; i >= 0; i--) {
        printf("%d", num[i]);
    }
    printf("\n");
}

//主函数，测试用例
int main() {
    int a, n;
    printf("请输入底数和指数：\n");
    scanf("%d%d", &a, &n);
    power(a, n);
    printf("%d的%d次方是：\n", a, n);
    print_num();
    return 0;
}