#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) { // 判断素数
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int count(int n, int max) { // 递归计数
    if (n == 0) {
        return 1; // 成功分解，返回 1
    }
    int cnt = 0;
    for (int i = 2; i <= max && i <= n; i++) { // 枚举素数 
        if (is_prime(i)) {
            cnt += count(n - i, i); // 递归计数 
        }
    }
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    int cnt = count(n, n); // 从 n 开始枚举
    printf("%d\n", cnt);
    return 0;
}