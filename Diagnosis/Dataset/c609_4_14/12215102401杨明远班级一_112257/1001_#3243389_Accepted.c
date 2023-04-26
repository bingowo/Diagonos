#include <string.h>
char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
void convert(int n, int r) {
    char result[50];
    int i = 0;

    // 将十进制数 n 转换成 R 进制数
    while (n) {
        result[i++] = digits[n % r];
        n /= r;
    }
    result[i] = '\0';

    // 翻转字符串并输出
    reverse(result);
    printf("%s\n", result);
}
int main() {
    int T,i;
    scanf("%d", &T);
    for (i = 0; i < T;i++) {
        int n, r;
        scanf("%d%d", &n, &r);
        if (n < 0) {
            printf("-"); n = -n;
        }
        convert(n, r);
    }
    return 0;
}