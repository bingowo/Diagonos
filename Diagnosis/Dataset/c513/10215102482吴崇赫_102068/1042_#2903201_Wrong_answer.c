#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define W 20

char* getDword(char* s)
{
    int p[128]={0};
    char* ret=(char*)malloc(W);
    for(int i=0;i<W;++i)ret[i]='\0';
    int n=strlen(s),pr=0;
    for(int i=0;i<n;++i){
        p[s[i]]++;
    }
    for(int k=0;k<128;++k){
        if(p[k])ret[pr++]=k;
    }
    return ret;
}

char* cut(char* s,int l,int len) //  l<=s<l+len
{
    char* ret=(char*)malloc(W);
    for(int i=0;i<W;++i)ret[i]='\0';
    int p=0;
    for(int i=l;i<l+len;++i)ret[p++]=s[i];
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
    char s[20];char temp[W]={0};
    gets(s);
    strcpy(temp,getDword(s));
    //printf("%s\n",temp);
    int n=strlen(temp);
    char ret[20][20];
    for(int i=0;i<20;++i){
        for(int k=0;k<20;++k)ret[i][k]='\0';
    }
    int p=0; // p->ret[i]
    // loops i->length of substring;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=n-i;++j)strcpy(ret[p++],cut(temp,j,i));
    }
    //printf("%s",ret[2]);
    qsort(ret,p,sizeof(ret[0]),cmp);
    printf("case #%d:\n",x++);
    for(int k=0;k<p;++k)printf("%s\n",ret[k]);
    }
    return 0;
}
