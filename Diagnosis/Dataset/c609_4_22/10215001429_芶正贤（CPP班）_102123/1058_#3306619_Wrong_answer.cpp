#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char input[105]; // 存储输入的10进制数
    int output[205]; // 存储转换后的-2进制数
    memset(output, 0, sizeof(output)); // 将output数组清零

    // 输入10进制数
    cout << "Please enter a decimal number: ";
    cin >> input;

    int len = strlen(input); // 10进制数的长度

    // 处理符号位
    bool negative = false; // 是否为负数
    if (input[0] == '-')
    {
        negative = true;
        for (int i = 0; i < len; i++)
        {
            input[i] = input[i+1]; // 将符号位去掉
        }
        len--;
    }

    // 转换为-2进制数
    int remainder = 0; // 余数
    for (int i = len-1; i >= 0; i--)
    {
        int digit = input[i] - '0'; // 当前位的数字
        digit += remainder * 10; // 加上上一位的余数
        remainder = digit % 2; // 计算当前位的余数
        digit /= 2; // 计算当前位的商
        if (remainder == 1) // 如果余数为1，需要向上一位借1
        {
            digit += 2; // 当前位加上2
            remainder = -1; // 下一位的余数减1
        }
        output[2*i+1] = digit % 2; // 存储当前位的最低位
        output[2*i] = digit / 2; // 存储当前位的次低位
    }
    output[0] = remainder; // 存储最高位的余数

    // 输出-2进制数
    cout << "The -2 base number is: ";
    if (negative) cout << "-"; // 如果是负数，输出符号位
    bool first_nonzero = false; // 是否找到第一个非零位
    for (int i = 0; i <= 2*len; i++)
    {
        if (output[i] != 0) first_nonzero = true; // 找到第一个非零位
        if (first_nonzero) cout << output[i]; // 输出非零位和零位
    }
    if (!first_nonzero) cout << "0"; // 如果所有位都是零，输出一个零

    cout << endl;
    return 0;
}
