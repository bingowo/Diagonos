#include <stdio.h>
#include <string.h>
#include <math.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    char s[20];
    scanf("%s", s);
    int a[3] = {0, 0, 0};
    int len = strlen(s);
    int sign = 1, k = 1;
    for (int i = 0; i < len; i++) {
        //x^2的系数
        if (s[i] == '^') {
            if (i == 1)
                a[0] = 1;
            else {
                for (int j = 0; j < i - 1; j++) {
                    a[0] = a[0] * 10 + s[j] - '0';
                }
            }
            i += 2;
        }
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
            if (s[i] >= '0' && s[i] <= '9') {
                while (i < len && (s[i] >= '0' && s[i] <= '9')) {
                    a[k] = a[k] * 10 + s[i] - '0';
                    i++;
                }
                a[k] = sign * a[k];
                k++;
                if (i == len && k == 2) {
                    a[k] = a[k - 1];
                    a[k - 1] = 0;
                }
            } else if (s[i] == 'x') {
                a[k] = sign;
                k++;
            }
        }
    }
    int d = a[1] * a[1] - a[0] * a[2] * 4;
    int x, y, z;
    int t[4];
    if (d < 0) {
        printf("No Answer!");
        return 0;
    } else {
        x = 2 * a[0];
        y = a[1] + sqrt(d);
        z = a[1] - sqrt(d);
        int g1 = gcd(x, y);
        int g2 = gcd(x, z);
        if (g1 < 0) {
            g1 = -g1;
        }
        if (g2 < 0) {
            g2 = -g2;
        }
        if (g1 > g2) {
            t[0] = x / g1;
            t[1] = y / g1;
            t[2] = x / g2;
            t[3] = z / g2;
        } else if (g1 < g2) {
            t[0] = x / g2;
            t[1] = y / g2;
            t[2] = x / g1;
            t[3] = z / g1;
        } else {
            t[0] = t[2] = x / g1;
            t[1] = z / g1;
            t[3] = y / g1;
        }
    }
    for (int i = 0; i < 4; i++) {
        printf("%d%c", t[i], (i == 3) ? '\n' : ' ');
    }
    return 0;
}
