#include <stdio.h>
#include <string.h>

int main()
{
    char str[10001];
    scanf("%s", str);

    int len = strlen(str);
    int max_fence = 0;

    for (int i = 0; i < len; i++) {
        int fence_len = 1; // 当前围栏的长度，初始化为 1
        int j = i + 1; // 搜索下一个字符的位置

        while (j < len && str[j] == str[i]) {
            j++; // 跳过连续相同的字符
        }

        if (j == len) {
            break; // 如果已经搜索到字符串末尾，退出循环
        }

        if (str[j] == '|' || str[j] == '-') {
            // 如果下一个字符是围栏中的字符，继续搜索
            while (j < len && str[j] != str[i]) {
                fence_len++;
                i = j; // 更新当前字符位置
                j++;
            }

            if (fence_len > max_fence) {
                max_fence = fence_len; // 更新最大围栏长度
            }
        }
    }

    printf("%d\n", max_fence);

    return 0;
}