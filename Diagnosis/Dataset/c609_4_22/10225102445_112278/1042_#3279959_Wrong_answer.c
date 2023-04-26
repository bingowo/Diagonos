#include <stdio.h>
#include <string.h>

typedef struct {
    char word[40];
    int length;
} Unit;

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int m;
        scanf("%d", &m);
        getchar(); // 读取回车符
        char str[2018];
        fgets(str, 2018, stdin); // 读取整行字符串
        int len = strlen(str);
        if (str[len - 1] == '\n') str[--len] = '\0'; // 去掉换行符
        Unit units[1000];
        int cnt = 0, cur_len = 0;
        for (int i = 0; i < len; i++) {
            char ch = str[i];
            if (ch == ' ') {
                if (cur_len > 0) { // 避免连续空格的情况
                    units[cnt].length = cur_len;
                    units[cnt++].word[cur_len] = '\0'; // 添加字符串结束符
                    cur_len = 0;
                }
            } else {
                units[cnt].word[cur_len++] = ch;
            }
        }
        if (cur_len > 0) { // 处理最后一个单词
            units[cnt].length = cur_len;
            units[cnt++].word[cur_len] = '\0';
        }
        printf("Case #%d:\n", t);
        int i = 0;
        while (i < cnt) {
            int j = i, cur_len = 0;
            while (j < cnt && cur_len + units[j].length <= m) {
                cur_len += units[j].length;
                j++;
                if (cur_len < m) cur_len++; // 加上空格
            }
            int num_words = j - i;
            int num_spaces = m - cur_len;
            for (int k = i; k < j; k++) {
                printf("%s", units[k].word);
                if (num_words == 1) { // 处理只有一个单词的情况
                    for (int s = 0; s < num_spaces; s++) putchar(' ');
                } else if (k < j - 1) { // 避免最后一个单词后面还有空格
                    int num_extra_spaces = num_spaces % (num_words - 1);
                    int num_even_spaces = num_spaces / (num_words - 1);
                    for (int s = 0; s < num_even_spaces; s++) putchar(' ');
                    if (k - i < num_extra_spaces) putchar(' ');
                }
            }
            putchar('\n');
            i = j;
        }
    }
    return 0;
}