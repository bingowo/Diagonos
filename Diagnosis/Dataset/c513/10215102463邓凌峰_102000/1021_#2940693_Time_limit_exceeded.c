#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char zmOrder[26];


typedef struct{
    char word[21];
}W;

int order(char c){
    char tmp=c;
    if(tmp=='\0') return -1;
    if('a'<tmp){tmp=tmp-32;}
    for(int j=0;j<26;j++){
        if(tmp==zmOrder[j]){
            return j;
        }
    }

}


int cmp(const void *a,const void *b){
    W pa=*(W*)a,pb=*(W*)b;
    int oa,ob;
    for(int i=0;i<21;i++){
        if(i==strlen(pa.word)) return -1;
        if(i==strlen(pb.word)) return 1;
        oa=order(pa.word[i]);
        ob=order(pb.word[i]);
        if(oa!=ob) return oa>ob?1:-1;
    }
}





int main()
{
    char panduan;
    while(scanf("%s",zmOrder)){
        W words[101]={0};
        int i=0;
        for(;scanf("%s",words[i].word);i++){
            char x=getchar();
            if(x=='\n') break;
        }
        qsort(words,i+1,sizeof(W),cmp);

        for(int j=0;j<=i;j++){
            printf("%s%c",words[j].word,j==i?'\n':' ');
        }
    }



}




