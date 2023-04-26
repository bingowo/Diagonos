#include <stdio.h>
#include <string.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    char s[30];
    scanf("%s", s);
    double n = 0;
    int dot_pos = -1; // 小数点位置
    int k = 0;
    while (s[k] != '\0') {
        if (s[k] == '.') {
            dot_pos = strlen(s) - k - 1;
        } else if (s[k] == '1') {
            n += pow(3, dot_pos - k - 1);
        } else if (s[k] == '2') {
            n -= pow(3, dot_pos - k - 1);
        }
        k++;
    }
    int numerator = round(n * pow(10, dot_pos)); // 转为分数形式
    int denominator = pow(10, dot_pos);
    int g = gcd(numerator, denominator); // 求最大公约数
    numerator /= g;
    denominator /= g;
    printf("%d", numerator / denominator); // 输出整数部分
    numerator %= denominator;
    if (numerator != 0) { // 如果有分数部分，输出带分数
        printf(" %d %d", numerator, denominator);
    }
    return 0;
}
