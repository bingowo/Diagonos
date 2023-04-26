#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char word[201];
    int length;
}W;

int inPut(W *words,char *s){
    int i=0,numLen=0,cnt=0,j=0;
    for(;i<strlen(s);i++){
        if(s[i]!=' '){
            numLen++;
            words[cnt].word[j++]=s[i];
        }
        else if(s[i]==' '){
            words[cnt++].length=numLen;
            numLen=0;
            j=0;
        }
         if(i==strlen(s)-1){
            words[cnt++].length=numLen;
        }
    }
    return cnt;
}


int cmp(const void *a,const void *b){
    char pa=*(char*)a,pb=*(char*)b;
    if(!isdigit(pa) && !isdigit(pb)) return pa>pb?1:-1;
    else if(!isdigit(pa)) 
    return -1;

}



int main()
{
    int n;scanf("%d",&n);
    char start=getchar();
    for(int i=0;i<n;i++){
        char sentence[201]={0};
        int wordLen[101]={0};
        char c=getchar();
        int cnt=0,len=0,j=0;
        do{
            if(c==' '){
                wordLen[cnt++]=len;
                len=0;
            }
            else{
                len++;
                sentence[j++]=c;
            }
            c=getchar();
        }while(c!='\n');
        wordLen[cnt]=len;


//        gets(sentence);
//        W words1[101]={0},words2[101]={0};
//        int cnt;
//        cnt=inPut(words1,sentence);

        qsort(sentence,strlen(sentence),sizeof(char),cmp);


        printf("case #%d:\n",i);
        puts(sentence);
    }

}







