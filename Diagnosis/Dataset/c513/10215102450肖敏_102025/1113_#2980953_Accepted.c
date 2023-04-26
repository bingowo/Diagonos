#include <stdio.h>
#include <stdlib.h>

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    int cnt[k][100];
    int i, j, m;
    for (i = 0; i < k; i++) {
        for (j = 0; j < 100; j++) {
            cnt[i][j] = 0;
        }
    }
    cnt[1][0] = 1;
    if (n == 1)printf("0\n");
    else if (n == 2)printf("1\n");
    else {
        for (i = 2; i < n; i++) {
            int sum, carry = 0;
            for (j = 0; j < 100; j++) {
                sum = 0;
                for (m = 0; m < k; m++) {
                    sum = sum + cnt[m][j];
                }
                sum = sum + carry;
                cnt[i % k][j] = sum % 10;
                carry = sum / 10;
            }
        }
        int key;
        for (key = 99; cnt[(n - 1) % k][key] == 0; key--);
        for (; key >= 0; key--) {
            printf("%d", cnt[(n - 1) % k][key]);
        }
    }
    return 0;
}

