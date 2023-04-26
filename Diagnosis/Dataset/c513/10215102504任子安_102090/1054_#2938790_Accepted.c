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
        char c = getchar();
        char s[L], line[m + 1];
        gets(s);
        int j = 0;
        printf("case #%d:\n", i);
        while(s[j]){
            int SpaceNum = 0, isWord = 0, CharacterNum = 0;
            int delta = 0, word = 0;
            while(s[j] == ' '){ j ++;}
            while(CharacterNum % m != m - 1 && s[j]){
                if(s[j] == ' '){
                    SpaceNum ++;
                    if(isWord == 1){ word ++;}
                    isWord = 0;
                    while(s[j] == ' '){ j ++;}
                    CharacterNum ++;
                }else{
                    isWord = 1;
                    j ++, CharacterNum ++;
                }
            }
            if(s[j] == '\0'){
                if(s[j - 1] == ' '){ CharacterNum --;}
                while(s[j] == ' ' || s[j] == '\0'){ j --;}
                for(int k = CharacterNum - 1, l = j; k >= 0; k --){
                    if(s[l] == ' '){
                        line[k] = s[l];
                        while(s[l] == ' '){ l --;}
                    }else{
                        line[k] = s[l--];
                    }
                }
                line[CharacterNum] = '\0';
                printf("%s\n", line);
                break;
            }
            if(!isspace(s[j])){
                if(s[j] && !isspace(s[j + 1])){ 
				while(s[j] != ' '){ j --, CharacterNum --;}
                while(s[j] == ' '){ j --;}
                CharacterNum --, SpaceNum --;
                }else{
                    word ++;
                }
            }else{
                SpaceNum ++;
                while(s[j] == ' '){ j --;}
                SpaceNum --, CharacterNum --;
                if(isWord){
                    isWord = 0;
                    word ++;
                }
            }
            delta = m - (CharacterNum + 1);
            int total = delta + SpaceNum;
            int SpaceGroup[L];
            memset(SpaceGroup, 0, sizeof(SpaceGroup));
            for(int k = word - 2; total > 0 ; total --){
                SpaceGroup[k] ++;
                k --;
                if(k < 0){ k = word - 2;}
            }
            for(int k = j, l = m - 1, index = word - 2, step = 0; l >= 0 ; k --){
                if(s[k] != ' '){
                    line[l --] = s[k];
                }else{
                    for(int r = SpaceGroup[index]; r > 0; r --){ line[l --] = ' ';}
                    index --;
                    while(s[k] == ' '){ k --;}
                    k ++;
                }
            }
            line[m] = '\0';
            printf("%s\n", line);
            j++;
        }
    }
    return 0;
}