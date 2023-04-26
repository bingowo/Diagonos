#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    char *aa = (char *)a;
    char *bb = (char *)b;
    return strcmp(aa, bb);
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for (int i = 0; i < T; i++) {
        char s[501];
        gets(s);

        int len = strlen(s);
        char str[501][15];
        int cnt = 0, k = 0;
        for (int j = 0; j < len; j++) {
            k = 0;
            while (s[j] >= 'a' && s[j] <= 'z') {
                 str[cnt][k++] = s[j++];
            }
            if (k) {
                str[cnt][k] = '\0';
                cnt++;
            }
            if (s[j] == ' ' || s[j] == ',' || s[j] == '.' || s[j] == '!' || s[j] == '?') {continue;}
        }
        //printf("----%d\n",cnt);

        qsort(str, cnt, sizeof(str[0]), cmp);
//        for (int j = 0; j < cnt; j++) {
//            printf("----%s\n",str[j]);
//        }

        printf("case #%d:\n", i);
        printf("%s",str[0]);
        for (int j = 1; j < cnt; j++) {
            if (strcmp(str[j], str[j-1]) != 0) printf(" %s", str[j]);
        }
        printf("\n");

    }
    return 0;
}
