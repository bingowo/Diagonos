#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    char s[100001];
    scanf("%s", s);
    int n = strlen(s);

    int len = 1;  // 当前的围栏长度
    int ans = 1;  // 最长的围栏长度
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {  // 当前字符和前一个字符不同
            len++;  // 围栏长度加 1
            if (len % 2 == 0) {  // 如果围栏长度为偶数
                int k = len / 2;  // 计算围栏中间的 | 的个数
                if (i-k >= 0 && s[i-k] == '|' && s[i] == '|') {
                    ans = max(ans, len);  // 更新最长的围栏长度
                }
            }
        } else {  // 当前字符和前一个字符相同，围栏被破坏了
            len = 1;  // 重置围栏长度为 1
        }
    }

    printf("%d\n", ans);

    return 0;
}
