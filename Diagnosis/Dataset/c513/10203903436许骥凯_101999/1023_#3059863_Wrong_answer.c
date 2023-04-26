#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calNum(char *s){
    int i = 0;
    for (; s[i] && !isdigit(s[i]); ++i);
    if (s[i]){
    	int res = 0;
        while(s[i] && isdigit(s[i])) res = res * 10 + s[i] - '0', ++i;
        return res;
    }
    else return -1;
}

int strnumcmp(char *s, char *t){
	if (calNum(s) == -1 && calNum(t) == -1) return strcmp(s, t);
    else return calNum(s) - calNum(t);
}

int cmp(const void* p1, const void* p2) {
    return strnumcmp(*(char(*)[31])p1, *(char(*)[31])p2);
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