#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 350

int max(int a,int b){return a>b?a:b;}

void reverse(char* s)
{
    char temp;
    for(int i=0,j=strlen(s)-1;i<j;++i,--j){
        temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

char* stringAdd(char* s,char* t)
{
    int lens=strlen(s);
    int lent=strlen(t);int m=max(lens,lent);
    reverse(s);reverse(t);
    int a[N];int b[N];int sum[N];
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)a[i]=b[i]=sum[i]=ret[i]=0;

    int ai=0,bi=0,si=0;
    for(int k=0;k<lens;++k)a[ai++]=s[k]-'0';
    for(int k=0;k<lent;++k)b[bi++]=t[k]-'0';
    for(int k=0;k<=m;++k){
        if(a[k]+b[k]>=10){
            sum[si++]=a[k]+b[k]-10;
            b[k+1]++;
        }
        else sum[si++]=a[k]+b[k];
    }
    while(sum[si]==0)si--;
    if(si<0)si=0;
    int pr=0;
    for(int i=si;i>-1;--i)ret[pr++]=sum[i]+'0';
    for(int i=0;i<N;++i)s[i]=0;
    strcpy(s,ret);
}

char* divideTwo(char* s)
{
    char* ret=(char*)malloc(N);int bei[N];
    for(int i=0;i<N;++i)ret[i]=bei[i]=0;
    for(int i=0;i<strlen(s);++i)bei[i]=s[i]-'0';
    int pr=0,yu=0;
    for(int i=0;i<strlen(s);++i){
        int b=yu*10+bei[i];
        ret[pr++]=b/2+'0';
        yu=b%2?1:0;
    }
    for(int i=0;i<N;++i)s[i]=0;
    int p=0,ps=0;
    if(strlen(ret)>1){
        while(ret[p]=='0')p++;
    }
    while(p<strlen(ret))s[ps++]=ret[p++];
}

int main()
{
    int T,x=0;scanf("%d\n",&T);
    while(T--){
    char s[N]={0};
    scanf("%s",s);
    char bin[N],real[N];int bi=0;int yu;
    for(int i=0;i<N;++i)bin[i]=real[i]=0;
    while(strcmp(s,"0")!=0){
        int sign=s[strlen(s)-1]-'0';
        yu=sign%2?1:0;
        bin[bi++]=yu+'0';
        divideTwo(s);
    }
    bi=0;
    if(strlen(bin)>1){
        while(bin[bi]=='0')bi++;
    }
    int r=0;
    while(bi<strlen(bin))real[r++]=bin[bi++];
    char ret[N]={0};
    for(int i=0;i<N;++i)ret[i]=0;
    ret[0]='0';
    for(int i=0;i<strlen(real);++i){
        char temp[N];for(int i=0;i<N;++i)temp[i]=0;
        strcpy(temp,ret);
        stringAdd(ret,temp);
        //printf("%s\n",ret);
        if(real[i]=='0')stringAdd(ret,"0");
        else stringAdd(ret,"1");
        //printf("%s\n",ret);
    }
    printf("case #%d:\n",x++);
    printf("%s\n",ret);}

    return 0;

}
