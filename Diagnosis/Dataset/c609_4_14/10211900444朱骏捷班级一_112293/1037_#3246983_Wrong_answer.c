#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000010];
    scanf("%s", s);
    int maxlen = 0; // 标记最长无重复子串长度
    int start = 0;  // 标记最长无重复子串的起始位置
    for (int t = 0; s[t]; t++)
    {
        int alpha[128] = {0};
        int len = 1;
        for (int i = t + 1; s[i] && alpha[s[i]] == 0; i++)
        {
            alpha[s[i]] = 1;
            len++;
            // 标记s[i] 出现过；
        }
        if (maxlen < len)
        {
            start = t;
            maxlen = len;
        }
    }

    // if (alpha[s[i]] == 0) // 表示s[i]没有在s[t]~s[i-1]出现过；

    for (int i = start; i < start + maxlen; i++)
        printf("%c", s[i]);
    printf("\n");
    return 0;
}
