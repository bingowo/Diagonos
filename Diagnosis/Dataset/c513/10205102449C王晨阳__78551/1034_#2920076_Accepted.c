#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float frequency[26];

int trans(char c) {
    if (c >= 'A' && c <= 'Z')
        return c;
    else
        return c - 32;
}

int cmp(const void *a, const void *b) {
    char a1 = *(char *) a;
    char b1 = *(char *) b;
    if(frequency[trans(a1)-'A'] != frequency[trans(b1)-'A']) {
        if (frequency[trans(a1)-'A'] > frequency[trans(b1)-'A'])
            return -1;
        else
            return 1;
    } else{
        if(trans(a1)== trans(b1))
            return b1-a1;
        else
            return trans(a1)- trans(b1);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 26; j++)
            scanf("%f", &frequency[j]);
        char s[101];
        scanf("%s", s);
        int len = strlen(s);
        qsort(s, len, sizeof(char), cmp);
        printf("case #%d:\n%s\n",i,s);
    }
    return 0;
}
