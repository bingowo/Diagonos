#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105

void lower(char* s)
{
    for(int i=0;i<strlen(s);++i){
        if(s[i]<='Z'&&s[i]>='A')s[i]=s[i]-'A'+'a';
    }
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        char input[N]={'\0'};
        char s[N][N];
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j)s[i][j]='\0';
        }
        gets(input);lower(input);
        int pi=0,pj=0;
        for(int k=0;k<strlen(input);++k){
            if(input[k]!=' ')s[pi][pj++]=input[k];
            else{
                pi++;pj=0;
            }
        }
        int cnt=0;
        for(int i=0;i<=pi;++i){
            if(!strcmp(s[i],"a")||!strcmp(s[i],"an")||!strcmp(s[i],"the")||!strcmp(s[i],"of")||!strcmp(s[i],"and")||!strcmp(s[i],"for"))cnt=cnt;
            else cnt++;
        }
        printf("case #%d:\n",x++);
        printf("%d\n",cnt);
    }
    return 0;
}

        