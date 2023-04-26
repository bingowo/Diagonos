#include <stdio.h>

int main() {
    char s[51]; // 字符串最长为50
    scanf("%s", s);

    int max_length = 0; // 最长围栏长度
    int curr_length = 0; // 当前围栏长度
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '|') {
            if (curr_length > 0 && curr_length > max_length) {
                max_length = curr_length;
            }
            curr_length = 0;
        }
        else if (s[i] == '-') {
            curr_length++;
        }
        i++;
    }

    if (curr_length > 0 && curr_length > max_length) {
        max_length = curr_length;
    }

    printf("%d\n", max_length);
    return 0;
}
