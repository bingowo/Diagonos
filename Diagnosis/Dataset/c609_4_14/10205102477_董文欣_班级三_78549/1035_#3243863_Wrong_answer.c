#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; i++) {
        char s[101];
        scanf("%s",s);
        int len = strlen(s);
        int first_remove[101];
        int cnt = 0;
        int ans = 0;
        for (int j = 0; j < len; j++) {
            if (s[j] != s[j+1]) {
                first_remove[cnt++] = s[j];
            }
            while (s[j] == s[j+1]) {j++;}
        }
        if (!cnt) ans = len + 1; //AAA情况
        else {
            for (int j = 2; j < cnt; j++) {
                if (first_remove[j-2] == first_remove[j]) { //隔一个相等 +4;
                    ans = (len - cnt) + 4; //len-cnt第一轮消除
                }
                else ans = (len - cnt) + 2;
            }
        }

        //for (int j = 0; j < cnt; j++) printf("%c",first_remove[j]);
        printf("case #%d:\n%d\n", i, ans);

    }
    return 0;
}
