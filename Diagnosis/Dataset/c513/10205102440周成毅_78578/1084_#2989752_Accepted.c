#include <stdio.h>

long long jilu[32];

void trans(int *array) {
    int flag = 1;
    for (int i = 3004; i > 0; i--) {
        array[i - 1] += array[i] / 10;
        array[i] %= 10;
    }
}

void multi(int *array, int num) {
    for (int i = 3004; i > 0; i--) {
        array[i] *= num;
    }
    trans(array);
}

void pow(int a, int b) {
    jilu[0] = 1;
    long long sum = 1;
    for (int i = 1; i <= b; i++) {
        sum *= a;
        jilu[i] = sum;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    pow(2, 31);
    for (int i = 0; i < T; i++) {
        printf("case #%d:\n", i);
        int n;
        scanf("%d", &n);
        printf("%lld\n", jilu[n]);
    }
    return 0;
}
