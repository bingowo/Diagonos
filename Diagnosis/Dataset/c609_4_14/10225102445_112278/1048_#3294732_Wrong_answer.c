#include <stdio.h>
#include <string.h>

// 大数位数和进制，这里为了方便测试，设置的比较小
#define MAX_LEN 1000
#define BASE 10

typedef struct {
    int digit[MAX_LEN]; // 数组模拟大数
    int len; // 大数的实际长度
} BigNum;

// 大数初始化为0
void init(BigNum* n) {
    memset(n->digit, 0, sizeof(n->digit));
    n->len = 1;
}

// 将字符串转换为大数
void from_string(BigNum* n, char* s) {
    int i, j, len = strlen(s);
    init(n);
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        n->digit[j] = s[i] - '0';
    }
    n->len = len;
}

// 大数赋值
void assign(BigNum* n1, BigNum* n2) {
    memcpy(n1->digit, n2->digit, sizeof(n2->digit));
    n1->len = n2->len;
}

// 大数加法
void add(BigNum* n1, BigNum* n2, BigNum* result) {
    init(result);
    int carry = 0, sum, i;
    for (i = 0; i < n1->len || i < n2->len; i++) {
        sum = n1->digit[i] + n2->digit[i] + carry;
        result->digit[i] = sum % BASE;
        carry = sum / BASE;
    }
    if (carry != 0) {
        result->digit[i] = carry;
        i++;
    }
    result->len = i;
}

// 大数输出
void print(BigNum* n) {
    int i;
    for (i = n->len - 1; i >= 0; i--) {
        printf("%d", n->digit[i]);
    }
}

// 斐波那契数列的第n项
void fibonacci(int n) {
    BigNum a, b, c;
    from_string(&a, "0");
    from_string(&b, "1");
    int i;
    for (i = 2; i <= n; i++) {
        add(&a, &b, &c);
        assign(&a, &b);
        assign(&b, &c);
    }
    printf("case #%d:\n", n);
    print(&a);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}
