#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 1000

char* getUser(char* s)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]='\0';
    for(int i=0;s[i]!='@';++i)ret[i]=s[i];
    return ret;
}

char* getAddr(char* s)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]='\0';
    int p=0,len=strlen(s);
    while(s[p]!='@')p++;
    ++p;int k=0;
    for(;p<len;++p)ret[k++]=s[p];
    return ret;
}

int cmp(const void* a,const void* b)
{
    char* c=(char*)a;char* s=(char*)b;
    if(strcmp(getAddr(c),getAddr(s))!=0)return strcmp(getAddr(c),getAddr(s));
    else return -strcmp(getUser(c),getUser(s));
}

int main()
{
    char s[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)s[i][j]='\0';
    }
    int n;
    scanf("%d\n",&n);
    for(int k=0;k<n;++k)scanf("%s",s[k]);
    qsort(s,n,sizeof(s[0]),cmp);
    for(int k=0;k<n;++k)printf("%s\n",s[k]);
    return 0;
}
