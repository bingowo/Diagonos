#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_sum_of_primes(int n) {
    bool *is_prime = (bool *)malloc(sizeof(bool) * (n+1));
    for (int i = 2; i*i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int *f = (int *)malloc(sizeof(int) * (n+1));
    f[0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            if (is_prime[j]) {
                f[i] += f[i-j];
            }
        }
    }

    int ans = f[n];
    free(f);
    free(is_prime);
    return ans;
}

int main() {
    int n = 10;
    int ans = count_sum_of_primes(n);
    printf("将%d分解成若干个素数之和的方案总数为：%d\n", n, ans);
    return 0;
}