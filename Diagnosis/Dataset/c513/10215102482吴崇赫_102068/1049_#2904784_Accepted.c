#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 505

int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}

int finds(char (*s)[505],char *t,int size)
{
    for(int i=0;i<size;++i){
        if(strcmp(s[i],t)==0)return 0;
    }
    return 1;
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
    //strcpy(temp,s);
    //printf("%s",temp);
    char t[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)t[i][j]='\0';
    }

    int pi=0,pj=0;
    for(int i=0;i<strlen(s)-1;++i){
        if(isalpha(s[i]))t[pi][pj++]=s[i];
        else if(!isalpha(s[i])&&isalpha(s[i+1])){pi++;pj=0;}
        else ;
    }
    if(isalpha(s[strlen(s)-1]))t[pi][pj]=s[strlen(s)-1];

    qsort(t,pi+1,sizeof(t[0]),cmp);

    char r[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)r[i][j]='\0';
    }
    //printf("%s",t[1]);

    int pr=0;
    for(int i=0;i<pi+1;++i){
        if(finds(r,t[i],pi+1)==1)strcpy(r[pr++],t[i]);
    }
    printf("case #%d:\n",x++);
    for(int i=0;i<pr;++i)printf("%s ",r[i]);
    printf("%s\n",r[pr]);}
    return 0;
}
