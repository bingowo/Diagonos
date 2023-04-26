#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int rmvdep(char words[][20], int n)
{
    int ret, i, j1 = 0, j2 = 1;
    if(n == 0){
        ret = 0;
    }else{
        char *word1, *word2;
        ret = 1;
        word1 = words[j1];
        word2 = words[j2];
        for(i = 1; i < n ; i ++){
            if(strcmp(word1, word2) != 0){
                word1 = words[++j1];
                strcpy(word1, word2);
                ret ++;
            }
            word2 = words[++j2];
        }
    }

    return ret;

}
int separate(char *sentence, char words[][20])
{
    int letter = 0;
    int i = 0;
    for(;*sentence;sentence ++){
        if(!isalpha(*sentence)){
            memmove(words[i], sentence - letter, letter * sizeof(char));
            words[i][letter] = '\0';
            i ++;
            letter = 0;
        }else{
            letter  ++;
        }
    }
    memmove(words[i], sentence - letter, letter * sizeof(char));
    words[i][letter] = '\0';
    i ++;
    return i;
}
int cmp(const void *a,const void *b)
{
    char *p1=(char*)a;
    char *p2=(char*)b;
    return *p1-*p2;
}
int main()
{
    int t;
    scanf("%d",&t);
    char c=getchar();
    for(int i=0;i<t;i++){
        char sentence[501];
        gets(sentence);
        char words [250][20];
        int letter_num=separate(sentence,words);
        qsort(words,letter_num-1,sizeof(words[0]),cmp);
        int words_del = rmvdep(words, letter_num);
        printf("case #%d:\n", i);
        for(int j = 0 ; j < words_del; j ++){
            if(words[j][0] != '\0'){
                printf("%s%c", words[j], (j == words_del - 1) ? '\n':' ');
            }
        }
    }

    return 0;
}

