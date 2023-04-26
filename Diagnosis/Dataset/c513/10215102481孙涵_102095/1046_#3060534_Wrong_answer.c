#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char word[101];
};

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int t = 0; t < T; t++){
        char s[101];
        gets(s);
        int len = strlen(s);
        struct data wordList[101];
        int pll = 0;
        int plr = 1;
        int cnt = 0;
        for(; plr < len; plr++){
            if(s[plr] == ' '){
                strncpy(wordList[cnt].word, s + pll, plr- pll);
                wordList[cnt].word[plr - pll] = '\0';
                pll = plr + 1;
                plr = plr + 1;
                cnt = cnt + 1;
            }
        }
        int cntWord = 0;
        for(int i = 0; i <= cnt; i++){
            if(strcmp(wordList[i].word, "the") == 0){}
            else if(strcmp(wordList[i].word, "a") == 0){}
            else if(strcmp(wordList[i].word, "an") == 0){}
            else if(strcmp(wordList[i].word, "of") == 0){}
            else if(strcmp(wordList[i].word, "for") == 0){}
            else if(strcmp(wordList[i].word, "and") == 0){}
            else{
                cntWord++;
            }

        }
        printf("case #%d:\n",t);
        printf("%d\n",cntWord);
    }
    return 0;
}
