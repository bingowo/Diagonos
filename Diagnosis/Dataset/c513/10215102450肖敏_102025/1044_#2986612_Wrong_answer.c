#include <stdio.h>
#include <string.h>

char hexi[16] = "0123456789abcdef";

int main() {
    char a[10001];
    scanf("%s", a);
    int len = strlen(a);
    long trans = 0;
    int has_hex = 0;
    long arr[10001] = {0};
    for (int i = 0; i < len; i++) {
        if (a[i] == '0' && a[i + 1] == 'x') {
            i += 2;
            int flag = 0;
            while ((a[i] >= '0' && a[i] < '9') || (a[i] >= 'a' && a[i] <= 'f')) {
                int j;
                for (j = 0; j < 16; j++) {
                    if (a[i] == hexi[j])
                        break;
                }
                arr[has_hex] *= 16;
                arr[has_hex] += j;
                flag = 1;
                i++;
                //停止有两种情况，一个是遇见了其他字符，第二个是遇见了0x//
                if (a[i] == 0 && a[i + 1] == 'x')
                    break;
            }
            if (flag)
                has_hex++;
        } else {
            continue;
        }
    }
    for (int i = 0; i < has_hex; i++) {
        printf("%ld ",arr[i]);
    }
    if (!has_hex) {
        printf("-1");
    }
}
