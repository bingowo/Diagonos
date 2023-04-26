#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int array[26];
int cmp(const void* a, const void* b){
    char* x = *((char**)a);
    char* y = *((char**)b);
    int len = (strlen(x)<strlen(y))?strlen(x):strlen(y);
    for(int i = 0; i < len; i++){
        int xi = (x[i]>='a')? array[x[i]-'a'] : array[x[i]-'A'];
        int yi = (y[i]>='a')? array[y[i]-'a'] : array[y[i]-'A'];
        if(xi == yi){
            if(i==len-1){return strlen(x)-strlen(y);}
            continue;
        }
        return xi - yi;
    }
}
int main(){
    char table[27];
    char s[40];
    char c;
    char *p;
    while(scanf("%s", table) != EOF){
        char** L = (char**)malloc(sizeof(char*)*100);
        int cnt = 0;
        for(int i = 0; i<26; i++){
            array[table[i]-'A'] = i+1;
        }
        for(cnt; cnt < 101; cnt++){
            scanf("%s", s);
            p = (char*)malloc(sizeof(char)*(strlen(s)+1));
            strcpy(p, s);
            *(L+cnt) = p;
            if(c=getchar() == '\n'){
                cnt++;
                break;
            }
        }
        qsort(L, cnt, sizeof(char*), cmp);
        for(int i = 0; i < cnt; i++){
            printf("%s", *(L+i));
            if(i<cnt-1){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
        free(L);
    }
    return 0;
}
