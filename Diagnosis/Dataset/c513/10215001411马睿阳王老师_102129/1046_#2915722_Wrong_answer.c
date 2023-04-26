#include <stdio.h>
int main() {
	char a[100];
    int i, in_word, word_num;
    gets(a);
    word_num = 0; // 初始化单词个数为0
    in_word = 0; // 标记位，标记是否在单词内
    for (i = 0; a[i]; i++) {
        if (a[i] == ' ') { // 检测到空格
            in_word = 0; // 设置标记位为不在单词内
        } else if (in_word == 0) { // 在单词内
            word_num++; // 统计单词个数
            in_word = 1; // 设置标记位为在单词内
        }
    }
    printf("%d", word_num);
}