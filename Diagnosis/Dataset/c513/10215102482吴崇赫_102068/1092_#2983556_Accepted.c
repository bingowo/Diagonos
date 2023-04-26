#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 1005

void reverse(char* s)
{
    char temp;
    for(int i=0,j=strlen(s)-1;i<j;++i,--j){
        temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

void multiple(char* s,int n)
{
    reverse(s);
    int c[N],a[N];int ai=0;
    for(int i=0;i<N;++i)c[i]=a[i]=0;
    for(int i=0;i<strlen(s);++i)a[ai++]=s[i]-'0';
    for(int i=0;i<ai;++i){
        c[i]+=a[i]*n;
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    ai++;
    while(c[ai]==0&&ai>0)ai--;
    //char ret[N];
    for(int i=0;i<N;++i)s[i]=0;
    for(int i=0;ai>-1;--ai,++i)s[i]=c[ai]+'0';
}

int main()
{
    char word[N],ret[N];
    int p[N];
    for(int i=0;i<N;++i)word[i]=p[i]=ret[i]=0;
    ret[0]='1';
    scanf("%s",word);
    int n=strlen(word);

    if(n==1){
        printf("1\n");
        return 0;
    }

    p[0]=(word[0]==word[1])?1:2;
    p[n-1]=(word[n-1]==word[n-2])?1:2;

    for(int i=1;i<n-1;++i){
        if(word[i]!=word[i-1]&&word[i]!=word[i+1])p[i]=3;
        if(word[i]==word[i-1]&&word[i]!=word[i+1])p[i]=2;
        if(word[i]!=word[i-1]&&word[i]==word[i+1])p[i]=2;
        if(word[i]!=word[i-1]&&word[i-1]==word[i+1])p[i]=2;
        if(word[i]==word[i-1]&&word[i]==word[i+1])p[i]=1;
    }

    for(int i=0;i<n;++i){
        multiple(ret,p[i]);
    }
    printf("%s\n",ret);

    return 0;
}
