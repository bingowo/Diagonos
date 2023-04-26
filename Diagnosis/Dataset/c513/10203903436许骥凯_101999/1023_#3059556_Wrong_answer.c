#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calNum(char* s) {
    int res = -1, i = 0;
    for (; s[i]; ++i)
        if (isdigit(s[i])) {
            res = 0;
            break;
        }
    if (res == 0)
        for (; s[i] && isdigit(s[i]); ++i)
            res = res * 10 + s[i] - '0';
    return res;
}

int cmp(const void* p1, const void* p2) {
    char *s1 = *(char(*)[31])p1, *s2 = *(char(*)[31])p2;
    int num1 = calNum(s1), num2 = calNum(s2);
    if (num1 == -1 && num2 == -1)
        return strcmp(s1, s2);
    return num1 - num2;
}

int main() {
    char arr_s[100][31], c;
    int arr_len = 0;
    do {
        scanf("%s", arr_s[arr_len++]);
    } while ((c = getchar()) != '\n');
    qsort(arr_s, arr_len, sizeof(arr_s[0]), cmp);
    for (int i = 0; i != arr_len; ++i)
        printf("%s%c", arr_s[i], i == arr_len - 1 ? '\n' : ' ');
    return 0;
}