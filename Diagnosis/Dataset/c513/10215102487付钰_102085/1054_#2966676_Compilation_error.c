#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define L 2100

int main(void)
{
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t; i ++){
        int m;
        scanf("%d", &m);
        //读掉多余的'\n'
        char c = getchar();
        char s[L], line[m + 1];
        gets(s);
        int j = 0;
        printf("case #%d:\n", i);

        while(s[j]){
            int SpaceNum = 0, isWord = 0, CharacterNum = 0;
            int delta = 0, word = 0;
            while(s[j] == ' '){ j ++;}
            //一边统计单词个数一边读取字符
            while(CharacterNum % m != m - 1 && s[j]){
                if(s[j] == ' '){
                    SpaceNum ++;
                    if(isWord == 1){ word ++;}
                    isWord = 0;
                    //多个连续的空格只读取一个空格
                    while(s[j] == ' '){ j ++;}
                    CharacterNum ++;
                }else{
                    isWord = 1;
                    j ++, CharacterNum ++;
                }
            }
            //如果是最后一行，那么就会读到'\0'
            if(s[j] == '\0'){
                //两行跳过多个连续空格
                if(s[j - 1] == ' '){ CharacterNum --;}
                while(s[j] == ' ' || s[j] == '\0'){ j --;}
                for(int k = CharacterNum - 1, l = j; k >= 0; k --){
                    if(s[l] == ' '){
                        line[k] = s[l];
                        //多个连续空格只要一个空格
                        while(s[l] == ' '){ l --;}
                    }else{
                        line[k] = s[l--];
                    }

                }
            