#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int differ_num(char *s) {
    int alpha[27] = {0};
    int len = strlen(s);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (alpha[s[i] - 'A']) continue;
        else {
                alpha[s[i] - 'A']++;
                ans++;
        }
    }
    return ans;
}

int cmp(const void *a, const void *b) {
    char *a1 = (char *)a;
    char *b1 = (char *)b;
    if (differ_num(b1) - differ_num(a1)) return (differ_num(b1) - differ_num(a1));
    else return strcmp(a1,b1);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d",&n);
        char s[n+1][21];
        for (int j = 0; j < n; j++) {
            scanf("%s",s[j]);
        }

        qsort(s, n, sizeof(s[0]), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j < n; j++) {
            printf("%s\n",s[j]);
        }

    }
    return 0;
}
