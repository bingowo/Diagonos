#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b);

struct data{
    char word[501];
};

int main(){
    int T;
    scanf("%d",&T);
    getchar();
    for(int t = 0; t < T; t++){
        char s[501];
        gets(s);
        int len = strlen(s);
        struct data wordList0[501];
        struct data wordList[501];
        int plw = 0;
        int pll = 0;
        int plr = 1;
        for(;plr < len; plr++){
            if(s[plr] == ',' || s[plr] == '.' || s[plr] == '!' || s[plr] == '?' || s[plr] == ' '){
                strncpy(wordList0[plw].word,s + pll, plr - pll);
                wordList0[plw].word[plr - pll] = '\0';
                pll = plr + 1;
                plw = plw + 1;
            }
        }
        int cnt = 0;
        int flag = 1;
        for(int i = 0; i < plw; i++){
            for(int j = 0; j < i; j++){
                if(strcmp(wordList0[j].word,wordList0[i].word) == 0){
                    flag = -1;

                }
            }
            if(flag == 1){
                strcpy(wordList[cnt].word,wordList0[i].word);
                cnt++;
            }
            flag = 1;
        }
        qsort(wordList,cnt,sizeof(wordList[0]),cmp);
        printf("case #%d:\n",t);
        for(int i = 0; i < cnt - 1 ; i++){
            printf("%s ",wordList[i].word);
        }
        printf("%s\n",wordList[cnt - 1].word);
    }
    return 0;
}

int cmp(const void *a, const void *b){
    struct data d1;
    struct data d2;
    d1 = (*(struct data *)a);
    d2 = (*(struct data *)b);
    if(strcmp(d1.word,d2.word) < 0){
        return -1;
    }else{
        return 1;
    }
}
