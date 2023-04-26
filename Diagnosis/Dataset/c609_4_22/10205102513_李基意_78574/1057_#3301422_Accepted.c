#include<stdio.h>

int g(int n) {
    int ret = 0;
    while (n % 5 == 0) {
        n /= 5;
        ++ret;
    }
    return ret;
}

int f(int n) {
    if (n < 5)
        return 0;
    else
        return f(n - 1) + g(n);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        printf("case #%d:\n%d\n", i, f(n));
    }
}