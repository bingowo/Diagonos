// A+B

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 120
typedef struct {
    int num[LEN];
    int sgn;
}BigInt;

BigInt stobi(char s[])
{
    char* p = NULL;
    BigInt bn;
    memset(&bn, 0, sizeof(bn));
    int idx = LEN - 1;
    bn.sgn = 1;
    for (p = s; *p; p++);
    while (1) {
        p--;
        if (*p != '-') {
            bn.num[idx--] = *p - '0';
        }
        if (p == s || *p == '-') {
            if (*p == '-') { bn.sgn = -1; }
            break;
        }
    }
    return bn;
}

int BigIntcmp(BigInt a, BigInt b)
{
    int ret = 0;
    if (a.sgn == 1 && b.sgn == -1) {
        ret = 1;
    }
    else if (a.sgn == -1 && b.sgn == 1) {
        ret = -1;
    }
    else {
        for (int i = 0; i < LEN; i++) {
            if (a.num[i] > b.num[i]) {
                ret = 1;
                break;
            }
            else if (a.num[i] < b.num[i]) {
                ret = -1;
                break;
            }
        }
        if (ret != 0) { ret *= a.sgn; }
    }
    return ret;
}

void PrintBigInt(BigInt bn)
{
    if (bn.sgn == -1) { printf("-"); }
    int idx;
    for (idx = 0; bn.num[idx] == 0 && idx < LEN; idx++);
    if (idx == LEN) {
        printf("0");
    }
    else {
        for (; idx < LEN; idx++) {
            printf("%d", bn.num[idx]);
        }
    }
}

BigInt add(BigInt a, BigInt b);
BigInt sub(BigInt a, BigInt b);

int main(void)
{
    char x[LEN], y[LEN];
    scanf("%s %s", x, y);
    if (x[0] == '0' && y[0] == '0') {
        printf("0");
    }
    else {
        BigInt a = stobi(x), b = stobi(y);
        PrintBigInt(add(a, b));
    }
    return 0;
}

BigInt add(BigInt a, BigInt b)
{
    BigInt ret;
    memset(&ret, 0, sizeof(ret));
    if (a.sgn * b.sgn == 1) {
        for (int i = LEN - 1; i > 0; i--) {
            ret.num[i] = ret.num[i] + a.num[i] + b.num[i];
            if (ret.num[i] >= 10) {
                ret.num[i] %= 10;
                ret.num[i - 1] += 1;
            }
        }
        ret.sgn = a.sgn;
    }
    else {
        if (a.sgn == 1) {
            b.sgn = 1;
            ret = sub(a, b);
        }
        else if (b.sgn == 1) {
            a.sgn = 1;
            ret = sub(b, a);
        }
    }

    return ret;
}

BigInt sub(BigInt a, BigInt b)
{
    BigInt ret;
    memset(&ret, 0, sizeof(ret));
    int c;
    if (a.sgn * b.sgn == 1) {
        if ((c = BigIntcmp(a, b) * a.sgn) == 1) {
            for (int i = LEN - 1; i; i--) {
                ret.num[i] = ret.num[i] + a.num[i] - b.num[i];
                if (ret.num[i] < 0) {
                    ret.num[i] += 10;
                    ret.num[i - 1] -= 1;
                }
            }
            ret.sgn = a.sgn;
        }
        else if (c == -1) {
            ret = sub(b, a);
            ret.sgn = a.sgn * -1;
        }
        else {
            ret.sgn = 1;
        }
    }
    else {
        if (a.sgn == 1) {
            b.sgn = 1;
            ret = add(a, b);
            ret.sgn = 1;
        }
        else {
            a.sgn = -1;
            ret = add(b, a);
            ret.sgn = -1;
        }
    }

    return ret;

}
