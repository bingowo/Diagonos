#include <stdio.h>

void print(unsigned long long ,unsigned long long);

int main() {
    int cnt = -1;
    char c;
    int arr[40000];
    while (1) {
        scanf("%c", &c);
        if (c == '\n')break;
        if (cnt > 0) {
            int tmp;
            if (c >= 'A' && c <= 'F')tmp = 10 + c - 'A';
            else tmp = c - '0';
            int i = 1;
            while (i <= 4) {
                arr[cnt * 4 - i] = tmp % 2;
                tmp /= 2;
                i++;
            }
        }
        cnt++;
    }
    cnt--;
    int qr = 0, qi = 0;
    int k = cnt * 4;
    int a, b;
    int j = 0;
    while (k) {
        a = -qr - qi + arr[j++];
        b = qr - qi;
        qr = a;
        qi = b;
        k--;
    }
    if (b == 0) {
        if (a == 0)
            printf("0");
        else
            printf("%d", a);
    } else {
        if (a == 0) {
            printf("%d", b);
            printf("i");
        }
        else {
            if (b == 1)
                printf("%d+i", a);
            else {
                if (b > 0) {
                    printf("%d+%d", a, b);
                    printf("i");
                }
                else {
                    printf("%d%d", a, b);
                    printf("i");
                }
            }
        }
    }

}
