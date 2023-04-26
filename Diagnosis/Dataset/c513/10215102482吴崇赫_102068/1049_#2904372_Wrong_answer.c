#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 505

char* keepWord(char* s)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]='\0';
    int pr=0;
    while(*s){
        if(isalpha(*s)||*s==' ')ret[pr++]=*s;
        s++;
    }
    return ret;
}

int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
    char s[N]={0};
    char *temp=(char*)malloc(N);
    for(int i=0;i<N;++i)temp[i]='\0';
    gets(s);
    strcpy(temp,keepWord(s));
    //printf("%s",temp);
    char t[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)t[i][j]='\0';
    } int pi=0,pj=0;
    for(int i=0;i<strlen(temp);++i){
        if(temp[i]==' '){pi++;pj=0;}
        else t[pi][pj++]=temp[i];
    }
    qsort(t,pi+1,sizeof(t[0]),cmp);
    printf("case #%d:\n",x++);
    for(int i=0;i<pi;++i)printf("%s ",t[i]);
    printf("%s\n",t[pi]);}
    return 0;
}
