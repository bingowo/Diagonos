#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int a[128];
        for (int j = 0; j < 128; j++) {
            a[j] = -1;
        }
        char s[60];
        int k = 2, flag = 0;
        scanf("%s", s);
        int len = strlen(s);
        for (int j = 0; j < len; j++) {
            if (j == 0) {
                a[s[j]] = 1;//第一个为1
            }
            if (flag == 0 && a[s[j]] == -1) {
                a[s[j]] = 0;//第一个与表示1的字符不同的为0
                flag = 1;
            }
            if (flag == 1 && a[s[j]] == -1) {
                a[s[j]] = k;
                k++;//k进制
            }
        }
        long long  min = 0;
        for (int j = 0; j < len; j++) {
            min = min * k + a[s[j]];
        }
        printf("case #%d:\n%lld\n", i, min);
    }
    return 0;
}
