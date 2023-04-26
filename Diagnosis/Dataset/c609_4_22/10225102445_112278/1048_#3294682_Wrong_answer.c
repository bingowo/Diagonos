#include <stdio.h>
#include <string.h>

#define MAX_DIGIT 1000

typedef struct {
    int digit[MAX_DIGIT];
    int len;
} BigInt;

void init(BigInt* num) {
    memset(num->digit, 0, sizeof(num->digit));
    num->len = 0;
}

void from_int(BigInt* num, int value) {
    init(num);
    do {
        num->digit[num->len++] = value % 10;
        value /= 10;
    } while (value);
}

void copy(BigInt* dest, BigInt* src) {
    memcpy(dest->digit, src->digit, sizeof(dest->digit));
    dest->len = src->len;
}

void add(BigInt* dest, BigInt* src1, BigInt* src2) {
    init(dest);
    int carry = 0;
    for (int i = 0; i < src1->len || i < src2->len || carry; i++) {
        int sum = src1->digit[i] + src2->digit[i] + carry;
        dest->digit[dest->len++] = sum % 10;
        carry = sum / 10;
    }
}

void print(BigInt* num) {
    for (int i = num->len - 1; i >= 0; i--) {
        printf("%d", num->digit[i]);
    }
}

void fib(int n) {
    BigInt a, b, c;
    from_int(&a, 0);
    from_int(&b, 1);
    for (int i = 2; i <= n; i++) {
        add(&c, &a, &b);
        copy(&a, &b);
        copy(&b, &c);
    }
    print(&b);
}

int main() {

    int n,i,T;
    scanf("%d\n", &T);
    for(i=0;i<=T-1;i++)
    {scanf("%d", &n);
    printf("case #%d:\n",i);
    fib(n);
    printf("\n");}
    return 0;
}