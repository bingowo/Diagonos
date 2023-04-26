#include <stdio.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    scanf("%d", &n);
    int num = 0, den = 1;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d/%d", &a, &b);
        num = num * b + den * a;//a=a1*b2+b1*a2
        den = den * b;//b=b1*b2
        //为了防止数据太大溢出，每次相加后将分子分母化简，即同时除以它们的最大公约数
        int g = gcd(num, den);
        num /= g;
        den /= g;
    }
    printf("%d/%d\n", num, den);
    return 0;
}