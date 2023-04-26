#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int cmp(const void* a, const void* b){
    char *s1=*(char**)a, *s2=*(char**)b;
    return strcmp(s1, s2);
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int j=0; j<T; ++j) {
        char s[501], *dic[500];
        gets(s);
        int i = 0, cnt = 0;
        while(s[i]) {
            char word[50];
            while(s[i] && !isalpha(s[i])) ++i;
            int k = 0;
            while(s[i] && isalpha(s[i])){
                word[k++] = s[i++];
            }
            word[k] = '\0';
            if(cnt == 0){
                dic[cnt] = (char*)malloc(50);
                strcpy(dic[cnt++], word);}
            else{
                for(k=0; k<cnt; ++k)
                    if(strcmp(word, dic[k])==0)
                        break;
                if(k == cnt) {
                    dic[cnt] = (char*)malloc(50);
                    strcpy(dic[cnt++], word);
                }
            }
        }
        qsort(dic, cnt, sizeof(char*), cmp);
        printf("case #%d:\n",j);
        for(int i=0; i<cnt; ++i){
            printf("%s%s",dic[i],i<cnt-1?" ":"\n");
            free(dic[i]);
        }
    }
    return 0;
}
