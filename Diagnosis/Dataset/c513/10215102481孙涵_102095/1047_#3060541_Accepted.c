#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char c;
    int num;
};

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    char chartable[256];
    for(int t = 0; t < T; t++){
        char s[501];
        gets(s);
        struct data wordList[501];
        int pl = 1;
        int pls = 0;
        wordList[0].c = s[0];
        wordList[0].num = 1;
        int len = strlen(s);
        for(; pl < len; pl++){
            if(wordList[pls].c == s[pl]){
                wordList[pls].num++;
            }else{
                pls++;
                wordList[pls].c = s[pl];
                wordList[pls].num = 1;
            }
        }
        printf("case #%d:\n",t);
        for(int i = 0; i <= pls; i++){
            int j = wordList[i].num / 255;
            int k = wordList[i].num % 255;
            if(j == 0){
                printf("%d%c",wordList[i].num,wordList[i].c);
            }else{
                for(int l = 0; l < j; l++){
                    printf("255%c",wordList[i].c);
                }
            }
            if(k != 0 && j != 0){
                printf("%d%c",k,wordList[i].c);
            }
        }
        printf("\n");
    }
    return 0;
}
