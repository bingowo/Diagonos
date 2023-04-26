#include <stdio.h>
#include <string.h>

int main() {
    int T, t;
    scanf("%d", &T);
    for (t = 0; t < T; t++) {
        int strLen, lineLen;
        char s[2001];
        scanf("%d\n", &lineLen);
        gets(s);
        strLen = strlen(s);

        printf("case #%d:\n", t);
        int i = 0;
        for (i = 0; s[i] == ' '; i++)
            ;   //跳过行首空格
        while (i < strLen) {
            int wordsCnt;   //wordsCnt:这一行的单词总数
            int wordsLen;   //wordsLen:这一行的单词总长度
            int space = 0;  //space:空格数
            
            int start = i;
            wordsLen = wordsCnt = 0;
            int p, l, j;
            while (wordsLen + wordsCnt <= lineLen && i < strLen) {
                for (p = i, l = 0; s[p] != ' ' && p < strLen; ++p, ++l)
                    ;
                if (wordsCnt + wordsLen + l <= lineLen) {
                    wordsLen += l;
                    ++wordsCnt;
                    for (i = p; s[i] == ' '; ++i)
                        ;
                }
                else
                    break;
            }
            space = lineLen - wordsLen;

            j = start;
            wordsCnt--;
            while (j < i) {
                while (s[j] != ' ' && j < strLen)
                    putchar(s[j++]);
                while (s[j] == ' ' && j < strLen)
                    ++j;
                    
                if (i == strLen && wordsCnt)
                    putchar(' ');
                else {
                    for (p = 0; wordsCnt && p < space / wordsCnt; ++p)
                        putchar(' ');
                    space -= p;
                }
                --wordsCnt;
            }
            putchar('\n');
        }
    }
    return 0;
}