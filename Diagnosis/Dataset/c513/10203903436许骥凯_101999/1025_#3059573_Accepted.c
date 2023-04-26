#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char s[21];
    int diff_cnt_char;
} String;

int calCnt(char* s) {
    int table[128] = {0}, cnt = 0;
    for (int i = 0; s[i]; ++i)
        if (table[s[i]] == 0)
            ++cnt, ++table[s[i]];
    return cnt;
}

int cmp(const void* p1, const void* p2) {
    String str_a = *(String*)p1, str_b = *(String*)p2;
    if (str_a.diff_cnt_char == str_b.diff_cnt_char)
        return strcmp(str_a.s, str_b.s);
    return str_b.diff_cnt_char - str_a.diff_cnt_char;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i != T; ++i) {
        int n;
        scanf("%d", &n);
        String arr_str[100];
        for (int j = 0; j != n; ++j) {
            scanf("%s", arr_str[j].s);
            arr_str[j].diff_cnt_char = calCnt(arr_str[j].s);
        }
        qsort(arr_str, n, sizeof(arr_str[0]), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j != n; ++j)
            printf("%s\n", arr_str[j].s);
    }
    return 0;
}