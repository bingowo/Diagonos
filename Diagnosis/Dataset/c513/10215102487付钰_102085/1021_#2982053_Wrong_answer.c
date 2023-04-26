#include <stdio.h>
#include <stdlib.h>

  //1-26
char s[100];
int p[26]={0};
int cmp(const void *a,const void *b)
{
char *s1,*s2;char ch1,ch2;
s1=(char **)a;s2=(char **)b;

while(*s1&&*s2)
{
ch1=(*s1)>='a'?*s1-32:*s1; // 转换为大写字母
ch2=(*s2)>='a'?*s2-32:*s2; // 转换为大写字母
if(p[ch1-'A']!=p[ch2-'A']) // 按字母顺序表比较字母
return p[ch1-'A']-p[ch2-'A'];
else {s1++;s2++;}
}
if(*s1==0) return -1;
else return 1;
}



int main() {
    while (scanf("%s\n", s) != EOF) {
        /**< initialize */
        char str[101][21];
        int i = 0, j = 0;
        for (int t = 0; t < 26; t++) {
            p[s[t]] = t;
            p[s[t] + 'a' - 'A'] = t;
        }
        /**< input string */
        char c;
        while ((c = getchar()) != '\n') {
            if (c == ' ') {
                c = getchar();
                str[i++][j] = '\0';
                j = 0;
            }
            str[i][j++] = c;
        }
        str[i++][j] = '\0';

        /**< sort */
        qsort(str, i, sizeof(str[0]), cmp);

        /**< output */
        printf("%s", str[0]);
        for (int k = 1; k < i; k++) {
            printf(" %s", str[k]);
        }
        printf("\n");
    }
    return 0;
}
