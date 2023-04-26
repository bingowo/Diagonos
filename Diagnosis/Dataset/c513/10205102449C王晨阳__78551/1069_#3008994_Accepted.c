#include <stdio.h>

int main() {
    int n;
    scanf("%d\n", &n);
    int n1 = n;
    int m = 0;
    int j = 0;
    while (m != n && j < 1000) {
        n = m + n;
        n1 = n;
        m = 0;
        while (n1 != 0) {
            int temp = n1 % 10;
            m = m * 10 + temp;
            n1 /= 10;
        }
        //printf("%d %d\n", n, m);
        j++;
    }
    printf("%d %d\n", j - 1, m);
    return 0;
}