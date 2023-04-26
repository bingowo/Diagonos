#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105

int Max(int a,int b){return a>b?a:b;}

void cleanS(char s[])
{
    char t[N]={0};
    int tp=0,i=0,j,n=strlen(s);
    while(i<n-1){
        if(s[i]!=s[i+1]){
            t[tp++]=s[i++];
        }
        else{
            j=i+1;
            while(s[i]==s[j])j++;
            i=j;
        }
    }
    if(n==1)t[tp++]=s[0];
    if(n>1&&s[n-1]!=s[n-2])t[tp++]=s[n-1];
    t[tp]=0;
    strcpy(s,t);
}

int hasSame(char s[])
{
    int n=strlen(s);
    if(n==1||n==0)return 0;
    for(int i=0;i<n-1;++i){
        if(s[i]==s[i+1])return 1;
    }
    return 0;
}

char* charu(char s[],int idx)
{
    char* ret=(char*)malloc(N);
    for(int i=0;i<N;++i)ret[i]=0;
    int i,j;
    for(i=0,j=0;i<=idx;++i,++j)ret[j]=s[i];
    ret[j++]=s[i-1];
    for(;i<strlen(s);++i,++j)ret[j]=s[i];
    return ret;
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        char s[N]={0};

        scanf("%s",s);
        //strcpy(t,charu(s,2));
        int p_n=strlen(s); // original length
        int max=0;
        for(int i=0;i<p_n;++i){
            char t[N]={0};
            strcpy(t,charu(s,i));
            while(hasSame(t))cleanS(t);
            int c_n=strlen(t);
            max=Max(max,p_n-c_n+1);
        }
        printf("case #%d:\n",x++);
        printf("%d\n",max);
    }
    return 0;
}
