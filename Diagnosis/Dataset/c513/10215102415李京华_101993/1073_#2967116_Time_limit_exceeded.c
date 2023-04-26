#include <stdio.h>

int miao(long long n) {
    if (n % 9 == 0)
        return 0;
    
    while (n) {
        if (n % 10 == 9)
            return 0;
        n /= 10;
    }
    return 1;
}

int main() {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    int cnt = 0;
    while (a <= b)
        cnt += miao(a++);
    
    printf("%d", cnt);

    return 0;
}