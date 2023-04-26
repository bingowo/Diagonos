#include <stdio.h>
#include <string.h>

#define MAX_LEN 2005
#define MAX_WORDS 205
#define MAX_LINE 75

char words[MAX_WORDS][MAX_LEN];
int words_len[MAX_WORDS];
int words_cnt;

int getline(char* str) {
    int len = 0;
    while ((*str = getchar()) != '\n') {
        if (*str == EOF) {
            return -1;
        }
        ++str;
        ++len;
    }
    *str = '\0';
    return len;
}

int count_space(int cnt, int width, int total) {
    if (cnt == 1) {
        return width - total;
    }
    int space = width - total;
    int k = space / (cnt - 1);
    int m = space % (cnt - 1);
    int result = k;
    if (m > 0) {
        ++result;
        --m;
    }
    return result;
}

void print_line(int start, int end, int width, int total) {
    int cnt = end - start;
    if (end == words_cnt) {
        for (int i = start; i < end; ++i) {
            if (i != start) {
                putchar(' ');
            }
            printf("%s", words[i]);
        }
        putchar('\n');
        return;
    }
    int space = count_space(cnt, width, total);
    int space_cnt = 0;
    for (int i = start; i < end; ++i) {
        if (i != start) {
            for (int j = 0; j < space; ++j) {
                putchar(' ');
            }
            if (space_cnt < width - total) {
                putchar(' ');
                ++space_cnt;
            }
        }
        printf("%s", words[i]);
    }
    putchar('\n');
}

void solve(int case_num) {
    int width;
    scanf("%d", &width);
    getchar();
    int len = getline(words[0]);
    if (len == -1) {
        return;
    }
    int ptr = 0;
    words_cnt = 0;
    while (ptr < len) {
        while (ptr < len && words[words_cnt][words_len[words_cnt] - 1] != ' ') {
            ++words_len[words_cnt];
            words[words_cnt][words_len[words_cnt] - 1] = words[words_cnt - 1][words_len[words_cnt - 1] - 1];
            ++ptr;
        }
        if (ptr < len) {
            ++words_cnt;
            words_len[words_cnt] = 0;
        }
    }
    ++words_cnt;
    int start = 0, end = 1, total = words_len[0];
    printf("case #%d:\n", case_num);
    while (end < words_cnt) {
        if (total + 1 + words_len[end] > width) {
            print_line(start, end, width, total);
            start = end;
            total = words_len[start];
        } else {
            total += 1 + words_len[end];
        }
        ++end;
    }
    print_line(start, end, width, total);
}

int main() {
    int case_num = 0;
    int t;
    scanf("%d", &t);
    getchar();
    while (t--) {
        solve(case_num++);
    }
    return 0;
}