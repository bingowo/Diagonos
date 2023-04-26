#include<stdio.h>
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int a[32] = {0};
        int maxLength = 0;
        int temp = 0;
        int i;
        int n;
        scanf("%d", &n);
        for (i = 0; n; i++) {
            a[i] = n % 2;
            n /= 2;
        }
        int k = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] != a[j + 1]) {
                maxLength++;
                if (temp < maxLength)
                    temp = maxLength;
                else temp = temp;
            }
            else {
                maxLength=0;
            }
        }
        printf("case #%d:\n%d\n", t, temp);
    }
    return 0;
}