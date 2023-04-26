#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}
char tmp[100];

void dfs(char *s, int n) {
    if (n == strlen(s)) return;

    int len = strlen(tmp);
    tmp[len] = s[n];
    tmp[len+1] = '\0';
    printf("%s\n", tmp);
    dfs(s, n + 1);
    tmp[len] = '\0';
    dfs(s, n + 1);
}

int main()
{
    int T;
    scanf("%d", &T);
    char s[17];
    for (int i = 0 ; i < T; i++) {
        scanf("%s", s);
        qsort(s, strlen(s), sizeof(s[0]), cmp);
        int cnt = 1;
        for (int j = 1; j < strlen(s); j++) {
            if (s[j] != s[j - 1]) s[cnt++] = s[j];
        }
        s[cnt] = '\0';

//        for (int j = 0; j < strlen(s); j++) {
//            printf("---%c ", s[j]);
//        }
//        printf("\n");
        tmp[0] = '\0';
        printf("case #%d:\n", i);
        dfs(s, 0);
    }
    return 0;
}
