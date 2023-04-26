#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char s[40];
    scanf("%s", s);
    long long a = 0, b = 0, qr, qi, sum = 0;
    int l = strlen(s), flag = 0, r = 0;
    for (int i = 0; i < l; i++) {
        if (isdigit(s[i])) {
            sum = sum * 10 + s[i] - '0';
            continue;
        } else if (s[i] == 'i') {
            if (flag == 1) {
                if (sum == 0)sum = 1;
                b = -sum;
                flag = 0;
                sum = 0;
            } else {
                
                if (sum == 0)sum = 1;
                b = sum;
                sum = 0;
            }
        } else if (s[i] == '+') {
            if (flag == 1) {
                a = -sum;
                flag = 0;
                sum = 0;
            } else {
                a = sum;
                sum = 0;
            }
        } else {
            if (i != 0) {
                if (flag) {
                    a = -sum;
                    sum = 0;
                } else {
                    a = sum;
                    sum = 0;
                }
            }
            flag = 1;
        }
    }
    if (s[l - 1] != 'i') {
        if (flag)
            a = -sum;
        else a = sum;
    }
    int k = 0;
    int ans[10001];
    memset(ans, 10001, 0);
    while (a != 0 || b != 0) {
        if ((a + b) % 2 == 0)r = 0;
        else r = 1;
        qr = (-a + b + r) / 2;
        qi = (-a - b + r) / 2;
        a = qr;
        b = qi;
        ans[k] = r;
        k++;
    }
    if (k == 0)printf("0");
    for (; k > 0; k--)printf("%d", ans[k - 1]);
    printf("\n");
    return 0;
}