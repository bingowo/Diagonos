#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 4000
#define BigNUm 10007


typedef struct{
    char word[20];
}W;

int cmp(const void *a,const void *b){
    W pa=*(W*)a,pb=*(W*)b;
    return strlen(pa.word)>strlen(pb.word)?-1:1;
}





int main(){

    int n;scanf("%d",&n);
    W words[LEN]={0};
    for(int i=0;i<n;i++) scanf("%s",words[i].word);
    char s[LEN]={0};scanf("%s",s);
    qsort(words,n,sizeof(W),cmp);

    char *p=s,*pf=NULL;
    while(*p){
        int idx=0;
        for(pf=NULL;idx<n;idx++){
            pf=strstr(p,words[idx].word);
            if(pf!=p) pf=NULL;
            else break;
        }
        if(!pf){
            printf("%c ",*p);
            p++;
        }
        else{
            printf("%s ",words[idx].word);
            p+=strlen(words[idx].word);
        }


    }


    return 0;
}
