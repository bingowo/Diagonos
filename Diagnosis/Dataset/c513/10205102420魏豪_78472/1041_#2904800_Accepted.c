#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char ch[51];
    int max_len = -1;
    scanf("%s", ch);
    for (int i = 0; i < strlen(ch); i++) 
    for (int j = i + 1; j <= strlen(ch); j++)
    if (judge(ch, i, j))
        max_len = (j - i) > max_len? (j - i): max_len;
    printf("%d\n", max_len);
    return 0;
}

int judge(char* ch, int l, int r) {
    char flag = ch[l];
    for (int i = l + 1; i < r; i++) {
        if (ch[i] == flag) return 0;
        flag = ch[i];
    }
    return 1;
}