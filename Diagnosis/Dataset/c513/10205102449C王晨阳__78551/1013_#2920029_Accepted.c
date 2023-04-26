#include<stdio.h>
#include<string.h>
#include <math.h>

long long GCD(long long x, long long y) {
    if (x % y == 0)return y;
    else return GCD(y, x % y);
}

int main() {
    char s[30];
    scanf("%s", s);
    int p = 0;
    int len = strlen(s);
    long long ansA = 0, ansB = 0, ansC = 1;
    for (; p < len; p++) {
        if (s[p] == '.')break;
        ansA *= 3;
        if (s[p] == '1')ansA += 1;
        if (s[p] == '2')ansA -= 1;
    }
    p++;
    for (; p < len; p++) {
        ansB *= 3;
        if (s[p] == '1')ansB += 1;
        if (s[p] == '2')ansB -= 1;
        ansC *= 3;
    }
    if (ansA > 0 && ansB < 0) {
        ansA--;
        ansB += ansC;
    } else if (ansA < 0 && ansB > 0) {
        ansA++;
        ansB = ansC - ansB;
        if (ansA == 0)ansB = -ansB;
    }
    long long t;
    t = GCD(abs(ansB), abs(ansC));
    if (ansB == 0)printf("%lld\n", ansA);
    else {
        if (ansA != 0)printf("%lld ", ansA);
        printf("%lld %lld\n", ansB / t, ansC / t);
    }
    return 0;
}