#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 4005
#define M 16

char* getStr(char* s,int left,int right)
{
    char* ret=(char*)malloc(M);
    int pr=0;
    for(int i=left;i<=right;++i)ret[pr++]=s[i];
    ret[pr]='\0';
    return ret;
}

int main()
{
    char word[N][M];char ret[N][M];
    int pr=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            word[i][j]=0;
            ret[i][j]=0;
        }
    }
    int T;scanf("%d\n",&T);
    int max=0;
    for(int i=0;i<T;++i){
        scanf("%s",word[i]);
        int len=strlen(word[i]);
        max=max>len?max:len;
    }
    int flag=0;
    char s[N];for(int i=0;i<N;++i)s[i]=0;
    scanf("%s",s);
    for(int i=0;i<strlen(s);){
        for(int j=i+max-1;j>=i;--j){
            flag=0;
            if(j>=strlen(s))continue;
            char* p=getStr(s,i,j);
            if(strlen(p)==1){
                strcpy(ret[pr++],p);
                i++;
                break;
            }
            for(int k=0;k<T;++k){
                if(strcmp(p,word[k])==0){
                    strcpy(ret[pr++],p);
                    i=j+1;flag=1;break;
                }
            }
            if(flag)break;
        }

    }
    for(int i=0;i<pr;++i)printf("%s ",ret[i]);
    return 0;
}
