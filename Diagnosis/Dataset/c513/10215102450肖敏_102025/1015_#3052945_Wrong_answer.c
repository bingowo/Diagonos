#include <stdio.h>
#include <string.h>

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    for (int t = 0; t < T; t++) {
        int A[26] = {0}, B[26] = {0};
        int a[30];
        char s[100];
        gets(s);
        int len = strlen(s);
        int q = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                q = i;
                break;
            }
        }
        int cnt1 = 0;
        for (int i = q - 1; i >= 0; i--) {
            if (s[i] == ',') {
                cnt1++;
            }
        }
        int k = 25 - cnt1;
        for (int i = 0; i < q; i++) {
            if (s[i] == ',')
                k++;
            else
                A[k] = A[k] * 10 + s[i] - '0';
        }
        int cnt2 = 0;
        for (int i = len-1; i > q; i--) {
            if (s[i] == ',') {
                cnt2++;
            }
        }
        int y = 25-cnt2;
        for (int i = q+1; i <len; i++) {
            if (s[i] == ',') {
                y++;
            } else
                B[y] = B[y] * 10 + s[i] - '0';
        }
        int cnt=cnt1>cnt2?cnt1:cnt2;
        int p = 25-cnt;
        int carry = 0, z = 0;
        for (int j = 25; j >= p; j--) {
            int sum = A[j] + B[j] + carry;
            if (sum >= prime[25 - j]) {
                sum -= prime[25 - j];
                carry = 1;
            } else {
                carry = 0;
            }
            a[z++] = sum;
        }
        if (carry)
            a[z] = carry;
        printf("case #%d:\n", t);
        for (int i = z; i >= 0; i--) {
            printf("%d%c", a[i], (i == 0) ? '\n' : ',');
        }
    }
}
