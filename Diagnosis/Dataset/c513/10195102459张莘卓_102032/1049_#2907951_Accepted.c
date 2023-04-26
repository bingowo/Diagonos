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
    int T;  scanf("%d",&T);
    getchar();
    for(int j=0; j<T; ++j) {
        char s[501];  gets(s);
        char **dic = (char**)malloc(500*sizeof(char*));
        int i = 0, cnt = 0;
        while(s[i]) {
            char word[50];
            while(s[i] && !isalpha(s[i])) ++i;
            if(s[i] == '\0') break;
            int k = 0;
            while(s[i] && isalpha(s[i]))
                word[k++] = s[i++];
            word[k] = '\0';
            for(k=0; k<cnt; ++k)
                if(strcmp(word, dic[k])==0)
                    break;
            if(k == cnt){
                dic[cnt] = (char*)malloc(15);
                strcpy(dic[cnt++], word);
            }
        }
        qsort(dic, cnt, sizeof(char*), cmp);
        printf("case #%d:\n",j);
        for(int i=0; i<cnt; ++i){
            printf("%s%s",dic[i],i<cnt-1?" ":"\n");
            free(dic[i]);
        }
        free(dic);
    }
    return 0;
}
