#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long int a = 0, b = 0, qr=1, qi=1;
    int r, k, t = 0, j = 0, sign, sign1, flag = 0, m = 0, n;
    char s[100], p[300];
    scanf("%s", s);
    int len = strlen(s);
    if (s[len - 1] == 'i')
        flag = 1;
    if (s[0] == '-') {
        sign = -1;
        t++;
    }
    if (!flag)//虚部为0
    {
        b = 0;
        for (k = t; k < len; k++)
            a = a * 10 + s[k] - '0';
        if (sign == -1)
            a = -a;
    } else {
        for (k = t; k < len; k++) {
            if (s[k] == '+' || s[k] == '-') {
                flag = 0;
                j = k;
                if (s[j + 1] == 'i')
                    b = 1;
            }
        }
        if (flag) {
            a = 0;
            for (k = t; k < len - 1 && b != 1; k++)
                b = b * 10 + s[k] - '0';
            if (sign == -1)
                b = -b;
        } else {
            for (k = t; k < j; k++)
                a = a * 10 + s[k] - '0';
            if (s[j] == '-')
                sign1 = -1;
            for (k = j + 1; k < len - 1 && b != 1; k++) {
                b = b * 10 + s[k] - '0';
            }
            if (sign == -1)
                a = -a;
            if (sign1 == -1)
                b = -b;
        }
    }

    while (qr != 0 || qi != 0) {
        if ((a % 2 == 0 && b % 2 == 0) || (abs(a) % 2 == 1 && abs(b) % 2 == 1))
            r = 0;
        else
            r = 1;
        p[m++] = r;
        qr = -(a - b - r) / 2;
        qi = -(a + b - r) / 2;
        a = qr;
        b = qi;
    }
    for (n = m - 1; n >= 0; n--)
        printf("%d", p[n]);

}
