#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{char word[20];}W;

void mystrlwr(char *ps)
{
    while(*ps){
        if('A'<= *ps && *ps<='Z')
            *ps+='a'-'A';
        ps++;
    }
}


int xx(char word[])
{
    mystrlwr(word);
    if(strcmp(word,"the")==0) return 0;
    if(strcmp(word,"a")==0) return 0;
    if(strcmp(word,"an")==0) return 0;
    if(strcmp(word,"of")==0) return 0;
    if(strcmp(word,"for")==0) return 0;
    if(strcmp(word,"and")==0) return 0;
    return 1;
}

int main()
{
    int T;scanf("%d",&T);
    char a=getchar();
    for(int i=0;i<T;++i){
        char s[101];
        gets(s);
        W words[100];
        for(int j=0;j<100;j++){
            words[j].word[0]='\0';
        }
        int a=0,b=0;
        for(int j=0;j<strlen(s);j++){
            if(j==0) words[a].word[b++]=s[j];
            else if(s[j]!=' ' && s[j-1]==' '){
                a++;b=0;
                words[a].word[b++]=s[j];
            }
            else if(s[j]!=' ' && s[j-1]!=' '){
                words[a].word[b++]=s[j];
            }
        }
        int ans=0;
        for(int j=0;j<a;j++){
            if(xx(words[j].word)) ans++;
        }
        printf("case #%d:\n%d\n",i,ans);


    }



    return 0;
}
