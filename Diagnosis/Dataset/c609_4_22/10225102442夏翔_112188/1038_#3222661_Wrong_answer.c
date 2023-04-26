#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp1(const void *a, const void *b){
    return strcmp(*(char**)a, *(char**)b);
}
int main(){
    int T, count, len;
    scanf("%d", &T);
    char **words;
    char c;
    getchar();
    for(int k=0; k<T; k++){
        words = (char**)malloc(sizeof(char*)*250);
        count = 0;
        len = 0;
        scanf("%c", &c);
        words[count] = (char*)calloc(500,sizeof(char));
        while(c!='\n'){
            if(c==' '||c==','||c=='.'||c=='?'||c=='!'){
                words[count][len] = '\0';
                count++;
                words[count] = (char*)calloc(500,sizeof(char));
                len = 0;
            }else{
                words[count][len++] = c;
            }
            scanf("%c", &c);
        }
        if(len!=0){
            words[count][len] = '\0';
            count++;
        }
        qsort(words, count,sizeof(words[0]),cmp1);
        printf("case #%d:\n", k);
        printf("%s", words[0]);
        for(int i=1; i<count; i++){
            if(strcmp(words[i-1],words[i])!=0)
                printf(" %s",words[i]);
        }
        printf("%c", '\n');
        for(int i=0; i<count; i++) free(words[i]);
        free(words);
    }
    return 0;
}