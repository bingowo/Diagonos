#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{char word[20];}W;

int panduan(char x)
{
    if(x==',') return 0;
    if(x=='.') return 0;
    if(x=='!') return 0;
    if(x=='?') return 0;
    return 1;
}


int chongfu(char s[],W wordBook[],int order)
{
    for(int i=0;i<order;i++){
        if(strcmp(s,wordBook[i].word)==0) return 0;
    }
    return 1;
}

int cmp(const void *a,const void *b)
{
    W pa=*(W*)a,pb=*(W*)b;
    return strcmp(pa.word,pb.word);
}



int main()
{
    int T;scanf("%d",&T);
    char xxxx=getchar();
    for(int i=0;i<T;i++){
        char s[501];
        gets(s);
        W words[100];
        for(int j=0;j<100;j++){
            for(int k=0;k<20;k++)
            words[j].word[k]='\0';
        }
        int a=0,b=0;
        for(int j=0;s[j];j++){
            if(j==0) words[a].word[b++]=s[j];
            else if(s[j]!=' ' && s[j-1]==' '){
                a++;b=0;
                words[a].word[b++]=s[j];
            }
            else if(s[j]!=' ' && s[j-1]!=' '){
                if(panduan(s[j])){words[a].word[b++]=s[j];}
                else{a++;b=0;}
            }
        }
        W wordBook[100];
        for(int j=0;j<100;j++){
            for(int k=0;k<20;k++)
            wordBook[j].word[k]='\0';
        }
        int order=0;
        char tmp[20];
        for(int cnt=0;cnt<=a;cnt++){
            char tmp[20];strcpy(tmp,words[cnt].word);
            if(cnt==0){
                strcpy(wordBook[order++].word,tmp);
            }
            else if(chongfu(tmp,wordBook,order)){
                strcpy(wordBook[order++].word,tmp);
            }

        }

        qsort(wordBook,order-1,sizeof(W),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<order;j++){
            printf("%s ",wordBook[j].word);
        }
        printf("\n");
    }
    return 0;
}
