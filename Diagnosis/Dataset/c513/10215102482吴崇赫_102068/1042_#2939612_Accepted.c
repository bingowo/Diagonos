#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define W 20
#define N 80000

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

int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}

int main()
{
    int T;scanf("%d\n",&T);
    int x=0;
    while(x<T){
    // input and erase the same word
    char input[W];
    scanf("%s",input);
    char temp[W];for(int i=0;i<W;++i)temp[i]='\0';
    strcpy(temp,getDword(input));

    //put each char into a new string
    char t[W][2];
    for(int i=0;i<W;++i){
        for(int j=0;j<2;++j)t[i][j]='\0';
    }
    int pt=0;
    for(int i=0;i<strlen(temp);++i)t[pt++][0]=temp[i];

    // solve the problem
    char ret[N][W];
    for(int i=0;i<N;++i){
        for(int j=0;j<W;++j)ret[i][j]='\0';
    }
    strcpy(ret[0],t[0]);
    int retSize=1;
    for(int k=1;k<pt;++k){
        char tr[N][W]; int flag=retSize;
        for(int i=0;i<N;++i){
            for(int j=0;j<W;++j)tr[i][j]='\0';
        }
        for(int i=0;i<flag;++i){
            strcpy(tr[i],ret[i]);
            strcat(tr[i],t[k]);
            strcpy(ret[retSize++],tr[i]);
        }
        strcpy(ret[retSize++],t[k]);
    }
    qsort(ret,retSize,sizeof(ret[0]),cmp);
    printf("case #%d:\n",x++);
    for(int i=0;i<retSize;++i)printf("%s\n",ret[i]);
    }
    return 0;
}
