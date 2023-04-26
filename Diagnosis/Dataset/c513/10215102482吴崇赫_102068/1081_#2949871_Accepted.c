#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3500

int max(int a,int b){return a>b?a:b;}

void reverse(char* s)
{
    char temp;
    for(int i=0,j=strlen(s)-1;i<j;++i,--j){
        temp=s[i];s[i]=s[j];s[j]=temp;
    }
}


char* multiple(char* s,char* t)
{
    int a[N],b[N];int ai=0,bi=0;
    int lens=strlen(s),lent=strlen(t);
    reverse(s);reverse(t);
    for(int i=0;i<lens;++i)a[ai++]=s[i]-'0';
    for(int i=0;i<lent;++i)b[bi++]=t[i]-'0';
    int c[N];for(int i=0;i<N;++i)c[i]=0;
    int ci=ai+bi;
    for(int i=0;i<ai;++i){
        for(int j=0;j<bi;++j){
            c[i+j]+=a[i]*b[j];
            c[i+j+1]+=c[i+j]/10;
            c[i+j]%=10;
        }
    }
    while(c[ci]==0&&ci>0)ci--;

    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]=s[i]=0;
    int pr=0;
    for(int i=ci;i>-1;--i)ret[pr++]=c[i]+'0';
    strcpy(s,ret);
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        char s[N];int n;
        for(int i=0;i<N;++i)s[i]=0;
        scanf("%s %d",s,&n);
        char* temp=(char*)malloc(N);
        for(int i=0;i<N;++i)temp[i]=0;
        temp[0]='1';
        for(int i=0;i<n;++i){
            multiple(temp,s);
        }
        printf("case #%d:\n",x++);
        printf("%s\n",temp);
    }
    return 0;
}
