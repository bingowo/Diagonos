#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000001];
//把出现过的字母放在一个整型的数组里面，出现一次+1
int main()
{
    scanf("%s",s);
    int len = strlen(s);
    int start = 0; //表示最长的子串从start数组下标开始
    int max = 1;
    for (int i = 0; i < len; i++) {
        int a[128] = {0};
        int cnt = 0;
        for (int j = i; j < len; j++) {
            if (a[s[j]]) break; //出现次数>1结束循环
            a[s[j]]++;
            cnt++;
        }

        if (cnt > max) {
            max = cnt;
            start = i;
        }
    }

    for (int i = start; i < start+max; i++) {
        printf("%c",s[i]);
    }
    return 0;
}
