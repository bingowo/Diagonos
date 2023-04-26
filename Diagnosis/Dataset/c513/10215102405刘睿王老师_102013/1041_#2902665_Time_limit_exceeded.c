//一个长度为n(0≤n≤50)的字符串s，s只包含‘| ’、‘-’字符。
//输出最长的由连续“|-”或连续“-|”组成的最长子串的长度。
#include <stdio.h>
#include <string.h>
#include <locale.h>
char s[51];
char s1[50],s2[50];
int i,L,L1,L2;
int main() {
    setlocale(LC_ALL,"chs");
    while (1) {
        printf("\n请输入一个最长50个字符且由|-组成的字符串(直接回车退出)：");
        fflush(stdout);
        rewind(stdin);
        fgets(s,50,stdin);
        if ('\n'==s[0]) break;
        L=strlen(s);
        if ('\n'==s[L-1]) s[L-1]=0;
        s[50]=0;
        L=strlen(s);
        for (i=0;i<L;i++) {
            if (s[i]!='|' && s[i]!='-') break;
        }
        if (i>=L) {
            for (i=0;i<50;i+=2) {
                s1[i]='|';
                s1[i+1]='-';
                s2[i]='-';
                s2[i+1]='|';
            }
            for (L1=50;L1>=0;L1-=2) {
                s1[L1]=0;
                if (strstr(s,s1)) break;
            }
            for (L2=50;L2>=0;L2-=2) {
                s2[L2]=0;
                if (strstr(s,s2)) break;
            }
            L=L1;
            if (L<L2) L=L2;
            printf("其中最长的由连续“|-”或连续“-|”组成的最长子串的长度为%d",L);
        }
    }
    return 0;
}
