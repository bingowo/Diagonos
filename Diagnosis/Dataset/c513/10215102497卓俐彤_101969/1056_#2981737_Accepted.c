#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct dic{
    char word[20];
};

int cmp(const void*a,const void*b){
    struct dic d1,d2;
    d1=*((struct dic*)a);
    d2=*((struct dic*)b);
    return strcmp(d2.word,d1.word);
}

int main(){
    int T;
    scanf("%d",&T);
    struct dic words[T];
    char str[5001];
    for(int t=0;t<T;t++){
        scanf("%s",words[t].word);
    }
    scanf("%s",str);
    char *p=str,*flag=NULL;
    qsort(words, T, sizeof(words[0]), cmp);
    int index=0;
    while(*p){
        for(index=0,flag=NULL;index<T;index++){
            flag=strstr(p,words[index].word);
            if(flag==p)break;
            else flag=NULL;
        }
        if(flag){
            p+=strlen(words[index].word);
            printf("%s",words[index].word);
        }
        else{
            printf("%c",*p);
            p++;
        }
        printf("%c",*p?' ':'\n');
    }
    return 0;
}
