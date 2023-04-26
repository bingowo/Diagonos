#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num(char *s) {
    int ret = 0;
    int i;
    int isdigit = 0;
    int end = 0;
    for (i = 0; i < strlen(s); ++i) {
        if (end)
            break;
        if (isdigit) {
            if (s[i] >= '0' && s[i] <= '9')
                ret = ret * 10 + s[i] - '0';
            else
                end = 1;
        }
        else {
            if (s[i] >= '0' && s[i] <= '9') {
                isdigit = 1;
                ret = s[i] - '0';
            }
        }
    }

    if (isdigit)
        return ret;
    return -1;
}

int cmp(const void *_a, const void *_b) {
    char *a = (char *)_a;
    char *b = (char *)_b;
    int anum = num(a);
    int bnum = num(b);

    if (anum != bnum)
        return anum - bnum;
    return strcmp(a, b);

}

int main() {
    int cnt = 0;
    char s[100][31];
    char tmp[31];
    while (scanf("%s", tmp) != EOF)
        strcpy(s[cnt++], tmp);    

    qsort(s, cnt, sizeof(s[0]), cmp);

    int i;
    for (i = 0; i < cnt - 1; ++i)
        printf("%s ", s[i]);
    printf("%s", s[i]);

    return 0;
}