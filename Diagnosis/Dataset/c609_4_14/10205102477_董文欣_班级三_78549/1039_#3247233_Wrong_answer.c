#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    char s1[81],s2[81],s[81];
    int ans = 0;
    int ans_left = 0, ans_right = 0;
    for (int i = 0; i < T; i++) {
        scanf("%s %s %s",s1, s2, s);
        int len = strlen(s);
        int len1 = strlen(s1), len2 = strlen(s2);
        //如果s中没有找到匹配的
        if (strstr(s,s1) == NULL || strstr(s,s2) == NULL) {
            ans = 0;
        }
        //printf("%s\n",strstr(s,s1));
        else if (!strcmp(s1,s2)) {
            ans = len - len1 - len2;
        }
        else {
            char *s11 = strstr(s,s1); //s1在左 s2在右
            int len11 = strlen(s11); //len11 - 从右边开始的s2的出现的index - len1即为间距
            int k = len2 - 1, j;
            for (j = len - 1; j >= 0; j--) {
                if (s[j] == s2[k]  && k > 0) {k--;}
                if (k == 0) break;
            }
            ans_left = len11 - (len - j) - len1 - 1;

            char *s22 = strstr(s,s2); //s2在左 s1在右
            int len22 = strlen(s22);
            k = len1 - 1;
            for (j = len - 1; j >= 0; j--) {
                if (s[j] == s1[k]  && k > 0) {k--;}
                if (k == 0) break;
            }
            ans_right = len22 - (len - j) - len2 - 1;

            ans = ans_left > 0 ? ans_left : ans_right;
        }
        printf("case #%d:\n%d\n", i, ans);
    }
    return 0;
}
